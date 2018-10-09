#include "string_vec.h"
#include "string.h"

void string_vec_print (string_vec * vec) {
    for (size_t y = 0; y < string_vec_length(vec); y++) {
        string s = string_vec_get(vec, y);
        string_print (&s);
    }
}

string_vec string_vec_from_raw (char ** strings, size_t length) {
    string_vec vec; string_vec_init (&vec);

    for (size_t i = 0; i < length; i++) {
        string string = string_from_raw(strings[i]);
        string_vec_push(&vec, string);
    }

    return vec;
}
