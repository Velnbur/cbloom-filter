#ifndef _BLOOMFILTER_H
#define _BLOOMFILTER_H

#include <stddef.h>
#include "bitarray.h"

typedef struct {
    size_t size;
    size_t hash_count;
    bitarray *bits;
} BloomFilter;

// Initialize bloom filter with predifined size and number of hashes.
void bloom_filter_init(BloomFilter *bf, size_t size, size_t hash_count);

// Free bloom filter by pointer.
void bloom_filter_free(BloomFilter* bf);

// Insert element into filter.
void bloom_filter_insert(BloomFilter* bf, const char* item);

// Check whether element is in filter or not.
bool bloom_filter_exists(BloomFilter* bf, const char* item);

#endif //_BLOOMFILTER_H
