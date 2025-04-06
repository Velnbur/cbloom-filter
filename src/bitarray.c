#include "bitarray.h"
#include <stdlib.h>

/// Initialize bitarray of size `length` in bits.
void bitarray_init(bitarray *ba, size_t length) {
    ba->length_in_bits = length;

    size_t length_in_bytes = length/8;

    ba->start = (char *)malloc(length_in_bytes);
}

/// Set bit of the array. Return -1 if overflow occure
int bitarray_set(bitarray *ba, size_t idx, bool value) {
    if (idx >= ba->length_in_bits) {
        return -1;
    }

    size_t byte_idx = idx / 8;
    size_t bit_idx = idx % 8;

    if (value) {
        ba->start[byte_idx] |= (1 << bit_idx);
    } else {
        ba->start[byte_idx] &= ~(1 << bit_idx);
    }

    return 0;
}

/// Get bit of the array
bool bitarray_get(bitarray *ba, size_t idx) {
    size_t byte_idx = idx / 8;
    size_t bit_idx = idx % 8;
    char byte = ba->start[byte_idx];
    return (byte & (1 << bit_idx)) != 0;
}

/// Free bitarray
void bitarray_free(bitarray *ba) {
    free(ba->start);
}
