#include "tuple.h"
#include "relation.h"
#include "database.h"
#include "string.h"

void tuple_init (tuple * tuple, relation * relation, string_vec data) {
    tuple->relation = relation;
    tuple->tuple_id = get_GUID(relation->database);
    tuple->data = data;
};

void tuple_free (tuple * this) {
    string_vec data = this->data;
    size_t length = string_vec_length (&data);
    
    for (size_t i = 0; i < length; i++) {
        string elem = string_vec_get(&data, i);
        char_vec_free (&elem);
    }
    string_vec_free(&data);
}


const size_t COLUMN_WIDTH = 18;
void tuple_query(tuple * this, string * str, size_t_vec cols) {
    size_t length = size_t_vec_length(&cols);
    for (size_t i = 0; i < length; i++) {
        size_t col = size_t_vec_get(&cols, i);
        string datum = string_vec_get(&this->data, col);

        string printable = string_new_fixedw(&datum, COLUMN_WIDTH);
        string_append(str, &printable);
        char_vec_free (&printable);
        string_append_raw(str, " ");
    }
    string_append_raw(str, "\n");
}
