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

#define T size_t
#include "vector.h"
#undef T

#define T char
#include "vector.h"
#undef T
typedef char_vec string;

#define T string
#include "vector.h"
#undef T

#define T string_vec
#include "vector.h"
#undef T

#include "../tuple.h"
#define T tuple
#include "vector.h"
#undef T

#include "../relation.h"
#define T relation
#include "vector.h"
#undef T

#endif /* GEN_VECTOR_H */
