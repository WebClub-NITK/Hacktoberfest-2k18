#ifndef INCLUDECFILE
#define INCLUDECFILE

#include "gen_vector.h"

#endif  /* INCLUDECFILE */


#ifdef T

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define STARTSIZE 8
#define GROWTHFACTOR 2

/* constructor */
void TP(T, _vec_init) (TP(T, _vec) * v) {
  v->data = malloc (sizeof( T ) * STARTSIZE );
  v->psize = STARTSIZE;
  v->lsize = 0;
}

/* returns the logical size of the vector */
size_t TP(T, _vec_length) ( TP(T, _vec) * v) {
  return v->lsize;
}

/* Push an element to the end of the vector. Returns the size of the
 * array. Will return 0 if there is not sufficient memory. */
size_t TP (T, _vec_push) ( TP(T, _vec) * v, T elem) {
  if (v->lsize == v->psize) {
    v->psize *= GROWTHFACTOR;
    
    T * block;
    block = realloc(v->data, sizeof( T ) * v->psize);

    if (block == NULL) {
      v->psize /= GROWTHFACTOR;
      return 0;
    }

    v->data = block;
  }

  v->data[v->lsize] = elem;
  v->lsize ++;
  return v->lsize;
}

T TP (T, _vec_pop) ( TP(T, _vec) * v) {
  assert (v->lsize > 0);

  v->lsize --;

  T value = v->data[v->lsize];
  if (v->lsize <= ((v->psize / 4) - STARTSIZE)) {
    v->psize /= GROWTHFACTOR;
    v->data = realloc(v->data, sizeof( T ) * v->psize);
  }
  return value;
}

void TP (T, _vec_set) ( TP(T, _vec) * v, size_t index, T elem) {
  assert (index < v->lsize);
  assert (index >= 0);

  v->data[index] = elem;
}

T TP(T, _vec_get) ( TP(T, _vec) * v, size_t index) {
  assert (index < v->lsize);
  assert (index >= 0);

  return v->data[index];
}

void TP (T, _vec_delete) ( TP(T, _vec) * v, size_t index) {
  assert (index < v->lsize);
  assert (index >= 0);
  assert (v->lsize > 0);

  v->lsize --;
  memmove(&v->data[index], &v->data[index + 1], sizeof( T ) * (v->lsize - index));

  if (v->lsize + STARTSIZE <= ((v->psize / 4))) {
    v->psize /= GROWTHFACTOR;
    v-> data = realloc(v->data, sizeof( T ) * v->psize);
  }
}

/* Insert an element into an array at index "index". If there is
   insuficcient memory, the function returns zero, otherwise it will
   return the new size of the array */
size_t TP (T, _vec_insert) ( TP(T, _vec) * v, size_t index, T elem) {
  assert (index < v->lsize);
  assert (index >= 0);

  if (v->lsize == v->psize) {
    v->psize *= GROWTHFACTOR;
    
    T * block;
    block = realloc(v->data, sizeof( T ) * v->psize);

    if (block == NULL) {
      v->psize /= GROWTHFACTOR;
      return 0;
    }

    v->data = block;
  }

  memmove(&v->data[index + 1], &v->data[index], sizeof( T ) * (v->lsize - index));

  v->data[index] = elem;
  v->lsize ++;
  return v->lsize;
}

size_t TP (T, _vec_reserve) ( TP(T, _vec) * v, size_t psize) {
  T * block;
  block = realloc(v->data, sizeof( T ) * psize);

  if (block == NULL) {
    return v->psize;
  }

  v->data = block;
  v->psize = psize;

  if (v->psize < v->lsize) {
    v->lsize = v->psize;
  }
  
  return psize;
}

void TP (T, _vec_free) ( TP(T, _vec) * v) {
  free (v->data);
}

#endif  /* T */
