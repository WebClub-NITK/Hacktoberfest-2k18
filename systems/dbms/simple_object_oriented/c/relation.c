#include "relation.h"

void relation_init (relation * this, database * database, string name,
                    string_vec row_names)
{
    tuple_vec data;
    tuple_vec_init(&data);

    this->name = name;
    this->relation_id = get_GUID(database);
    this->database = database;
    this->row_names = row_names;
    this->data = data;
}
