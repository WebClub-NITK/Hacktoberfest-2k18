#ifndef RELATION_H
#define RELATION_H

typedef struct database database;

#include <stddef.h>
#include "vector/gen_vector.h"
#include "tuple.h"

typedef struct relation {
    string name;
    size_t relation_id;
    database * database;
    string_vec col_names;
    tuple_vec data;
} relation;

void relation_init (relation * this, database * database, string table_name,
                    string_vec row_names);
void relation_free (relation * this);

void relation_from_csv (relation * this, const char * filename);

string relation_query (relation * this, string_vec columns, size_t num);

#endif
