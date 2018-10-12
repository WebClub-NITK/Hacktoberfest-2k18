#ifndef STRING_H
#define STRING_H

#include "vector/gen_vector.h"

void string_append_raw (string * str, char * raw);
void string_append (string * str1, string * str2);
string string_from_raw (char * raw);

void string_print (string * str);
string string_new_fixedw (string * str, size_t len);

int string_cmp (string * a, string * b);

#endif
