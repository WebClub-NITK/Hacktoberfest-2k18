#include <stdio.h>
#include <stdlib.h>

#include "relation.h"
#include "tuple.h"
#include "database.h"
#include "string.h"
#include "parsecsv.h"

void relation_init (relation * this, database * database, string name,
                    string_vec col_names)
{
    tuple_vec data;
    tuple_vec_init(&data);

    this->name = name;
    this->relation_id = get_GUID(database);
    this->database = database;
    this->col_names = col_names;
    this->data = data;
}

void relation_free (relation * this) {
    size_t length;
    tuple_vec data = this->data;
    string_vec col_names = this->col_names;
    
    char_vec_free(&this->name);

    length = tuple_vec_length (&data);
    for (size_t i = 0; i < length; i++) {
        tuple elem = tuple_vec_get(&data, i);
        tuple_free (&elem);
    }
    tuple_vec_free(&data);

    length = string_vec_length (&col_names);
    for (size_t i = 0; i < length; i++) {
        string elem = string_vec_get(&col_names, i);
        char_vec_free (&elem);
    }
    string_vec_free(&col_names);
}

void relation_from_csv (relation * this, const char * filename) {
    FILE * file = fopen (filename, "r");
    char c;
    string_vec_vec raw_data; string_vec_vec_init (&raw_data);
    tuple_vec * data = &(this->data);
    string s; char_vec_init (&s);

    while (EOF != (c = fgetc(file))) {
        char_vec_push(&s, c);
    }
    char_vec_push(&s, '\0');

    parse_csv (&raw_data, s.data);

    size_t length = string_vec_vec_length(&raw_data);
    for (size_t i = 0; i < length; i++) {
        string_vec tuple_data = string_vec_vec_get(&raw_data, i);
        if (string_vec_length (&tuple_data) != string_vec_length(&this->col_names)) {
            puts ("CSV file has wrong number of columns.");
            exit(1);
        }
        tuple tuple; tuple_init (&tuple, this, tuple_data);
        tuple_vec_push(data, tuple);
    }
    
    fclose (file);
    char_vec_free(&s);
    string_vec_vec_free(&raw_data);
}

string relation_query (relation * this, string_vec columns, size_t num) {
    size_t_vec cols; size_t_vec_init(&cols);
    
    size_t l1 = string_vec_length(&columns);
    size_t l2 = string_vec_length(&this->col_names);
    
    for (size_t i = 0; i < l1; i++) {
        string name1 = string_vec_get(&columns, i);
        
        for (size_t j = 0; j < l2; j++) {
            string name2 = string_vec_get(&this->col_names, j);
            
            if (0 == string_cmp(&name1, &name2)) {
                size_t_vec_push (&cols, j);
            }
        }
    }

    size_t rownum = tuple_vec_length(&this->data);
    num = num < rownum ? num : rownum;
    string s; char_vec_init(&s);
    for (size_t i = 0; i < num; i++) {
        tuple tuple = tuple_vec_get(&this->data, i);
        tuple_query (&tuple, &s, cols);
    }
    
    size_t_vec_free (&cols);
    return s;
}
