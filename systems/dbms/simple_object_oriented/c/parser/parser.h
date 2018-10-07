#ifndef PARSER_H
#define PARSER_H

#include "../vector/gen_vector.h"

typedef struct parse_result {
    char * error;
    char * next_pos;
} parse_result;

parse_result parse_reject (char * msg);
parse_result parse_accept (char * new_string);

parse_result parse_EOF (char * str);

int parse_is_error (parse_result result);

parse_result parse_any_char (char * c, char * str);
parse_result parse_char (char this, char * str);
parse_result parse_not_char (char * c, char not_this, char * str);
parse_result parse_one_of (char * c, char * these, char * str);
parse_result parse_none_of (char * c, char * not_these, char * str);

parse_result parse_string (char * cmp_str, char * str);
parse_result parse_many_of (string * result, char * these, char * str);
parse_result parse_until_one_of (string * result, char * these, char * str);

parse_result parse_eat_whitespace (char * str);
parse_result parse_eat_whitespace_and_newlines (char * str);
parse_result parse_nl_or_cr (char * str);

#endif
