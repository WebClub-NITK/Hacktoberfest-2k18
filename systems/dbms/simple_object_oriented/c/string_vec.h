#ifndef STRING_VEC_H
#define STRING_VEC_H

#include <stddef.h>

#include "vector/gen_vector.h"

void string_vec_print (string_vec * vec);
string_vec string_vec_from_raw (char ** strings, size_t length);

#endif
