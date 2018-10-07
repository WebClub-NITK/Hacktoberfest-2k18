#include "table.h"
#include "database.h"

void tuple_init (tuple * tuple, Database * database, relation * table, string_vec data) {
    tuple->database = database;
    tuple->table = table;
    tuple->tupl_id = get_GUID(database);
    tuple->data = data;
};
