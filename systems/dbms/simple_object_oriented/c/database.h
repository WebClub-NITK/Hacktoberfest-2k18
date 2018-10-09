#ifndef DATABASE_H
#define DATABASE_H

typedef struct relation_vec relation_vec;

#include "relation.h"
#include "vector/gen_vector.h"

typedef struct database {
    relation_vec relations;
    size_t current_GUID;
    string_vec log;
} database;

void database_init (database * this);
void database_free (database * this);

size_t get_GUID (database * this);

string database_query (database * this, string_vec columns, string tablename,
                       size_t num);

#endif
