#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "string_vec.h"
#include "string.h"
#include "database.h"
#include "parser/parser.h"
#include "vector/gen_vector.h"

parse_result parse_comma_separated (string_vec * results, char * str);

const int VALID_QUERY = 0;
const int EXIT_CMD = 1;
const int INVALID_QUERY = 2;
int parse_query (string_vec * columns, string * table, int * limit, char * str) {    
    parse_result pos;
    
    pos = parse_eat_whitespace(str);
    pos = parse_string("EXIT", pos.next_pos);
    if (!parse_is_error(pos)) {
        return EXIT_CMD;
    }

    pos = parse_eat_whitespace(str);
    pos = parse_string ("SELECT", pos.next_pos);
    if (parse_is_error(pos)) {
        return INVALID_QUERY;
    }

    pos = parse_comma_separated (columns, pos.next_pos);
    if (parse_is_error(pos)) {
        return INVALID_QUERY;
    }

    pos = parse_string ("FROM", pos.next_pos);
    if (parse_is_error(pos)) {
        return INVALID_QUERY;
    }
    pos = parse_eat_whitespace(pos.next_pos);
    
    char * old_pos = pos.next_pos;
    pos = parse_until_one_of(table, " ,\n\t", pos.next_pos);
    if (pos.next_pos == old_pos) {
        return INVALID_QUERY;
    }
    
    pos = parse_eat_whitespace(pos.next_pos);
    pos = parse_string ("LIMIT", pos.next_pos);
    if (parse_is_error(pos)) {
        return INVALID_QUERY;
    }
    pos = parse_eat_whitespace(pos.next_pos);

    char * next_pos;
    *limit = strtol(pos.next_pos, &next_pos, 10);
    
    return VALID_QUERY;
}

parse_result parse_comma_separated (string_vec * columns, char * str) {
    parse_result pos = parse_eat_whitespace(str);
    
    string column; char_vec_init(&column);
    char * old_pos = pos.next_pos;
    pos = parse_until_one_of(&column, " ,\n\t", pos.next_pos);
    
    while (pos.next_pos != old_pos) {
        pos = parse_eat_whitespace (pos.next_pos);    
        string_vec_push (columns, column);

        old_pos = pos.next_pos;
        pos = parse_char(',', pos.next_pos);
        
        if (parse_is_error(pos)) {
            return parse_accept(old_pos);
        }
        
        pos = parse_eat_whitespace (pos.next_pos); 
        
        char_vec_init (&column);
        old_pos = pos.next_pos;
        pos = parse_until_one_of(&column, " ,\n\t", pos.next_pos);
    }

    char_vec_free (&column);
    return pos;  
}


int main (int argc, char** argv) {
    database db;
    time_t curtime;
    database_init(&db);
    FILE * log = fopen("data/log.txt", "a");

    char user_id[1024];
    char line_buf[1024];

    printf("User ID: ");
    fgets(user_id, 1023, stdin);  

    while (1) {
        string_vec columns; string_vec_init(&columns);
        char_vec table; char_vec_init(&table);
        int limit;
        
        printf("\ndb> ");
        
        fgets(line_buf, 1023, stdin);
        
        int result = parse_query (&columns, &table, &limit, line_buf);
        if (EXIT_CMD == result) {
            break;
        }
        else if (INVALID_QUERY == result) {
            puts ("Invalid query, queries are of the form 'SELECT column1, column2, ..., columnN FROM tablename LIMIT limit'");
            continue;
        }
        
        string s = database_query(&db, columns, table, limit);
        string_print (&s);
        char_vec_free(&s);

        
        time(&curtime);
        fprintf(log, "%s %s %s\n", user_id, ctime(&curtime), line_buf);
        
        char_vec_free (&table);
        string_vec_free (&columns);
    }

    database_free(&db);
    return 0;
}
