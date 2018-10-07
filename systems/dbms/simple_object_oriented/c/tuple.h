#ifndef TUPLE_H
#define TUPLE_H

#include "vector/gen_vector.h"
#include <stddef.h>

typedef struct tuple {
    size_t table_id;
    size_t tuple_id;
    string_vec data;
} tuple

void tuple_init (size_t table_id, string_vec data);

#endif
