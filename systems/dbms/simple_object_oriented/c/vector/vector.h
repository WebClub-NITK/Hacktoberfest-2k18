#ifdef T

#include <stddef.h>

typedef struct TP(T, _vector) {
  T * data;
  size_t psize;
  size_t lsize;
} TP(T, _vector);

void TP(T, _vec_init) ( TP(T, _vector) * v);
void TP (T, _vec_free) ( TP(T, _vector) * v);

size_t TP(T, _vec_length) ( TP(T, _vector) * v);

size_t TP (T, _vec_push) ( TP(T, _vector) * v, T elem);
T TP (T, _vec_pop) ( TP(T, _vector) * v);

void TP (T, _vec_set) ( TP(T, _vector) * v, size_t index, T elem);
T TP(T, _vec_get) ( TP(T, _vector) * v, size_t index);

size_t TP (T, _vec_insert) ( TP(T, _vector) * v, size_t index, T elem);
void TP (T, _vec_delete) ( TP(T, _vector) * v, size_t index);

size_t TP (T, _vec_reserve) ( TP(T, _vector) * v, size_t psize);

#ifdef INCLUDECFILE
#include "vector.c"
#endif

#endif  /* T */
