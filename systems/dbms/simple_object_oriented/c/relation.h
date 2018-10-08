#ifndef RELATION_H
#define RELATION_H

#include "vector/gen_vector.h"
#include "database.h"
#include "tuple.h"

typedef struct relation {
    size_t relation_id;
    database * database;
    string_vec row_names;
    tuple_vec data;
} relation;

void relation_init (relation * this, database * database, string_vec row_names);

#endif
