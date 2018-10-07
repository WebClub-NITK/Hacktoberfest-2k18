#include <stdio.h>

#include "parsecsv.h"
#include "vector/gen_vector.h"

char_vector read_string () {
    char c;
    string s;
  
    char_vec_init(&s);
  
    while (EOF != (c = getchar())) {
        char_vec_push(&s, c);
    }
    char_vec_push(&s, '\0');

    return s;
}

void print_string_vec_vec (string_vec_vec * svv) {
    string_vec_vec lines = *svv;
    for (size_t x = 0; x < string_vec_vec_length(&lines); x++) {
        string_vec line = string_vec_vec_get(&lines, x);

        for (size_t y = 0; y < string_vec_length(&line); y++) {
            string field = string_vec_get(&line, y);
            printf("|%s|\t", field.data);
        }
        printf("\n");
    }
}

void removeCommas (void) {
    string input = read_string();
    int status;
    string_vec_vec db;
    string_vec_vec_init(&db);
    
    parse_csv (&db, input.data);

    print_string_vec_vec (&db);
}


int main (int argc, char** argv) {
    removeCommas();

    return 0;
}
