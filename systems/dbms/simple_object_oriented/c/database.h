#ifndef DATABASE_H
#define DATABASE_H

#include "vector/gen_vector.h"
#include "table.h"

typedef struct database {
    table_vec tables;
    size_t current_GUID;
    string_vec log;
} tuple

size_t get_GUID (database * database);

#endif
