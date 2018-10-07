#include "database.h"

size_t get_GUID (database * database) {
    database->currentGUID +=1;
    return datatbase->currentGUID; 
}
