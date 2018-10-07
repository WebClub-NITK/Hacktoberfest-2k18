#include <stdio.h>
#include "parser/parser.h"
#include "parsecsv.h"

void print_string (string str) {
    for (size_t x = 0; x < char_vec_length(&str); x++) {
        putchar (char_vec_get(&str, x));
    }
}

void print_string_vec (string_vec * vec) {
    for (size_t y = 0; y < string_vec_length(vec); y++) {
        print_string (string_vec_get(vec, y));
    }
}

static parse_result parse_file (string_vec_vector * result, char * str);
static parse_result parse_record (string_vector * result, char * str);
static parse_result parse_field (string * result, char * str);
static parse_result escaped (string * result, char * str);
static parse_result inner_escaped (string * result, char * str);
static parse_result single_escaped_char (char * result, char * str);
static parse_result non_escaped (string * result, char * str);

int parse_csv (string_vec_vector * db, char * str) {
    parse_result pos;
    pos = parse_file (db, str);

    if (parse_is_error(pos)) {
        puts (pos.error);
        return -1;
    }
    
    return 0;
};


static parse_result parse_file (string_vec_vector * result, char * str) {
    parse_result pos;
    string_vector record;
    string_vec_init (&record);

    pos = parse_record (&record, str);

    while (!parse_is_error(pos)) {
        string_vec_vec_push (result, record);
        str = pos.next_pos;

        pos = parse_nl_or_cr(str);
        if (parse_is_error(pos)) {
            return parse_EOF(str);
        }
        if (!parse_is_error(parse_EOF(pos.next_pos))){
            return parse_accept(pos.next_pos);
        }

        string_vec_init (&record);
        pos = parse_record (&record, pos.next_pos);
    }
    
    string_vec_free (&record);
    return pos;
}

static parse_result parse_record (string_vector * result, char * str) {
    parse_result pos;
    string field;
    char_vec_init (&field);
    
    pos = parse_field (&field, str);

    while (!parse_is_error(pos)) {
        string_vec_push (result, field);
        str = pos.next_pos;
        
        pos = parse_char(',', pos.next_pos);
        if (parse_is_error(pos)) {
            return parse_accept(str);
        }

        char_vec_init (&field);
        pos = parse_field (&field, pos.next_pos);
    }
    
    char_vec_free (&field);
    return pos;
}

static parse_result parse_field (string * result, char * str) {
    parse_result pos;
    
    pos = escaped (result, str);
    if (!parse_is_error(pos)) {
        return pos;
    }
    return non_escaped (result, str);
}

static parse_result escaped (string * result, char * str) {
    parse_result pos;

    pos = parse_eat_whitespace (str);
    pos = parse_char ('"', pos.next_pos);
    if (parse_is_error(pos)) {
        return pos;
    }
    
    pos = inner_escaped (result, pos.next_pos);
    if (parse_is_error(pos)) {
        return pos;
    }

    pos = parse_char ('"', pos.next_pos);
    if (parse_is_error(pos)) {
        return pos;
    }
    return parse_eat_whitespace (pos.next_pos);
}

static parse_result inner_escaped (string * result, char * str) {
    char c;
    parse_result pos = single_escaped_char (&c, str);
    
    while (!parse_is_error(pos)) {
        char_vec_push (result, c);
        str = pos.next_pos;
        pos = single_escaped_char (&c, str);
    }
    return parse_accept (str);
}

static parse_result single_escaped_char (char * result, char * str) {
    parse_result pos;

    pos = parse_not_char (result, '"', str);
    if (!parse_is_error(pos)) {
        return pos;
    }

    *result = '"';
    return parse_string ("\"\"", str);
}

static parse_result non_escaped (string * result, char * str) {
    return parse_until_one_of(result, ",\"\n\r", str);
}
