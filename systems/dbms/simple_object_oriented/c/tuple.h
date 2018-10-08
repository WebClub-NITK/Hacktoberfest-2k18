#ifndef TUPLE_H
#define TUPLE_H

#include "vector/gen_vector.h"
#include "relation.h"
#include <stddef.h>

typedef struct tuple {
    relation * table;
    size_t tuple_id;
    string_vec data;
} tuple

void tuple_init (size_t table_id, string_vec data);

#endif
