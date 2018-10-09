#ifndef TUPLE_H
#define TUPLE_H

#include <stddef.h>

typedef struct relation relation;
typedef struct tuple tuple;

#include "vector/gen_vector.h"

typedef struct tuple {
    relation * relation;
    size_t tuple_id;
    string_vec data;
} tuple;

void tuple_init (tuple * tuple, relation * relation, string_vec data);
void tuple_free (tuple * this);

void tuple_query(tuple * this, string * str, size_t_vec cols);

#endif
