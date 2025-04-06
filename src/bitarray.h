#ifndef _BITARRAY_H
#define _BITARRAY_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    char* start;
    size_t length_in_bits;
} bitarray;

/// Initialize bitarray of size `length` in bits.
void bitarray_init(bitarray *ba, size_t length);

/// Set bit of the array. Return -1 if value is out of range
int bitarray_set(bitarray *ba, size_t idx, bool value);

/// Get bit of the array
bool bitarray_get(bitarray *ba, size_t idx);

/// Free bitarray
void bitarray_free(bitarray *ba);

#endif // _BITARRAY_H
