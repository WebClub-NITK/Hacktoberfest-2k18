#ifndef GEN_VECTOR_H
#define GEN_VECTOR_H

/* template macro */

#define TP(a, b) CAT(a, b)
#define CAT(a, b) a ## b

/* Define your types here. For example if you want to have a vector of
 * int, include the following lines:
 *
 * #define T int
 * #include "vector.h"
 * #undef T     
 *
 * The vector functions can then be invoked as "int_vec_init",
 * "int_vec_push", "int_vec_get" etc
 */

#include "table.h"

#define T char
#include "vector.h"
#undef T
typedef char_vector string;

#define T string
#include "vector.h"
#undef T
typedef string_vector string_vec;

#define T string_vec
#include "vector.h"
#undef T
typedef string_vec_vector string_vec_vec;

#define T table
#include "vector.h"
#undef T

#endif /* GEN_VECTOR_H */
