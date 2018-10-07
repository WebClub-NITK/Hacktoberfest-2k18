#include "parser.h"

int parse_is_error (parse_result result) {
    if (result.next_pos == NULL) {
        return 1;
    }
    return 0;
}

parse_result parse_reject (char * msg) {
    parse_result pos = {msg, NULL};
    return pos;
}

parse_result parse_accept (char * new_string) {
    parse_result pos = {"", new_string};
    return pos;
}

parse_result parse_EOF (char * str) {
    if ('\0' == *str) {
        return parse_accept (str);
    }
    return parse_reject ("parse_EOF: not EOF.");
}

parse_result parse_char (char this, char * str) {
    if (*str == '\0') {
        return parse_reject ("char: unexpected EOF.");
    }

    if (*str != this) {
        return parse_reject ("char: unexpected character.");
    }

    return parse_accept (str + 1);
}

parse_result parse_not_char (char * c, char not_this, char * str) {
    if (*str == '\0') {
        return parse_reject ("not_char: unexpected EOF.");
    }

    *c = *str;    
    if (*str == not_this) {
        return parse_reject ("not_char: unexpected character.");
    }

    return parse_accept (str + 1);
}

parse_result parse_any_char (char * c, char * str) {
    if (*str == '\0') {
        return parse_reject ("any_char: unexpected EOF.");
    }
    
    *c = *str;
    return parse_accept (str + 1);
}

parse_result parse_none_of (char * c, char * not_these, char * str) {
    if (*str == '\0') {
        return parse_reject ("none_of: unexpected EOF.");
    }

    *c = *str;
    
    for (; not_these != '\0'; not_these ++) {
        if (*c == *not_these) {
            return parse_reject ("none_of: unexpected Character.");
        }
    }

    return parse_accept (str + 1);
}

parse_result parse_one_of (char * c, char * these, char * str) {
    if (*str == '\0') {
        return parse_reject ("one_of: unexpected EOF.");
    }

    *c = *str;
    
    for (; these != '\0'; these ++) {
        if (*c == *these) {        
            return parse_accept (str + 1);
        }
    }

    return parse_reject ("one_of: unexpected character.");
}

parse_result parse_string (char * cmp_str, char * str) {
    while (*str == *cmp_str && *str != '\0' && *cmp_str != '\0') {
        str++;
        cmp_str++;
    }

    if (*cmp_str != '\0') {
        return parse_reject ("string: mismatched string");
    }

    return parse_accept (str);
}

parse_result parse_many_of (string * result, char * these, char * str) {
    for (; *str != '\0'; str++) {
        char * c = these;

        for (; *c != '\0'; c++) {
            if (*str == *c) {        
                char_vec_push (result, *str);
                break;
            }
        }

        /* Not one of the given characters */
        if (*c == '\0') {
            return parse_accept(str);
        }
    }

    /* Will always accept, but may give an empty result.*/
    return parse_accept(str);
}

parse_result parse_until_one_of (string * result, char * these, char * str) {
    for (; *str != '\0'; str++) {
        char * c = these;

        for (; *c != '\0'; c++) {
            if (*str == *c) {        
                return parse_accept (str);
            }
        }

        /* Not one of the given characters */
        char_vec_push (result, *str);
    }

    /* Will always accept, but may give an empty result.*/
    return parse_accept(str);
}

parse_result parse_eat_whitespace (char * str) {
    for (; *str != '\0'; str++) {
        if (*str != ' ' && *str != '\t') {        
            break;
        }
    }
    
    return parse_accept(str);
}

parse_result parse_eat_whitespace_and_newlines (char * str) {
    for (; *str != '\0'; str++) {
        if (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\r') {        
            break;
        }
    }
    
    return parse_accept(str);
}

parse_result parse_nl_or_cr (char * str) {
    if (*str == '\0') {
        return parse_reject ("nl_or_cr: unexpected EOF.");
    }
    if (*str != '\n' && *str != '\r') {
        return parse_reject ("nl_or_cr: expecting at least one carriage return or newline.");
    }
    for (; *str != '\0'; str++) {
        if (*str != '\n' && *str != '\r') {
            break;
        }
    }
    return parse_accept(str);
}
