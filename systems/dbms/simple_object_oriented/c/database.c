#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#include "database.h"
#include "relation.h"
#include "string_vec.h"
#include "string.h"

void database_init (database * this) {
    relation_vec relations; relation_vec_init(&relations);
    string_vec log; string_vec_init(&log);

    string name1 = string_from_raw ("StudentDetails");
    char * stud_details_rows_raw[5] = {
        "Name",
        "Department",
        "CGPA",
        "RollNo",
        "Graduation_Year"
    };
    string_vec stud_details_rows =
        string_vec_from_raw (stud_details_rows_raw, 5);
    relation student_details;
    relation_init(&student_details, this, name1, stud_details_rows);
    relation_from_csv(&student_details, "data/StudentDetails.csv");

    string name2 = string_from_raw ("MarksDetails");
    char * marks_details_rows_raw[4] = {
        "Student_RollNo",
        "Subject1_Marks",
        "Subject2_Marks",
        "Subject3_Marks"
    };
    string_vec marks_details_rows =
        string_vec_from_raw (marks_details_rows_raw, 4);
    relation marks_details;
    relation_init(&marks_details, this, name2, marks_details_rows);
    relation_from_csv(&marks_details, "data/MarksDetails.csv");

    relation_vec_push(&relations, student_details);
    relation_vec_push(&relations, marks_details);   
    
    this->current_GUID = 0;
    this->log = log;
    this->relations = relations;
}

void database_free (database * this) {
    size_t length;
    relation_vec relations = this->relations;
    string_vec log = this->log;
    
    length = relation_vec_length (&relations);
    for (size_t i = 0; i < length; i++) {
        relation elem = relation_vec_get(&relations, i);
        relation_free (&elem);
    }
    relation_vec_free(&relations);

    length = string_vec_length (&log);
    for (size_t i = 0; i < length; i++) {
        string elem = string_vec_get(&log, i);
        char_vec_free (&elem);
    }
    string_vec_free(&log);
}

size_t get_GUID (database * this) {
    this->current_GUID +=1;
    return this->current_GUID;
}

string database_query (database * this, string_vec columns, string tablename,
                       size_t num)
{
    relation_vec * relations = &this->relations;
    size_t length = relation_vec_length(relations);
    string s;

    for (size_t i = 0; i < length; i++) {
        relation relation = relation_vec_get(relations, i);
        if (0 == string_cmp(&tablename, &relation.name)) {
            s = relation_query (&relation, columns, num);
            return s;
        }
    }
    exit (1);
}
