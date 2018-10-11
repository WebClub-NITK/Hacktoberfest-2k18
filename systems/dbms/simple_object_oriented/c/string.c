#include "string.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>

void string_append_raw (string * str, char * raw) {
    for (; *raw != '\0'; raw++) {
        char_vec_push(str, *raw);
    }
}
void string_append (string * str1, string * str2) {
    size_t length = char_vec_length (str2);
    for (size_t i = 0; i < length; i++) {
        char c = char_vec_get(str2, i);
        char_vec_push(str1, c);
    }
}

string string_from_raw (char * raw) {
    string str; char_vec_init(&str);
    string_append_raw (&str, raw);
    return str;
}

void string_print (string * str) {
    size_t length = char_vec_length (str);
    for (size_t x = 0; x < length; x++) {
        putchar (char_vec_get(str, x));
    }
}

string string_new_fixedw (string * str, size_t len) {
    string new; char_vec_init(&new);
    size_t orig_len = char_vec_length(str);
    if (orig_len <= len) {
        string_append(&new, str);
        for (; orig_len < len; orig_len++) {
            char_vec_push(&new, ' ');
        }
    }
    else {
        for (size_t i = 0; i < len - 3; i++) {
            char_vec_push (&new, char_vec_get(str, i));
        }
        string_append_raw (&new, "...");
    }
    return new;
}

int string_cmp (string * a, string * b) {
    size_t l1 = char_vec_length(a);
    size_t l2 = char_vec_length(b);
    size_t min = l1 < l2 ? l1 : l2;

    int result = memcmp (a->data, b->data, min);
    if (result != 0) {
        return result;
    }
    
    return l1 - l2;
}
