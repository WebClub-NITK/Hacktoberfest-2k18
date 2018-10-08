#include "table.h"
#include "database.h"

void tuple_init (tuple * tuple, relation * relation, string_vec data) {
    tuple->relation = relation;
    tuple->tuple_id = get_GUID(table->database);
    tuple->data = data;
};
