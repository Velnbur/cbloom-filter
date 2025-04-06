#include "bloomfilter.h"
#include "bitarray.h"

#include <stdlib.h>
#include "komihash.h"

// Initialize bloom filter with predifined size and number of hashes.
extern void bloom_filter_init(BloomFilter *bf, size_t size, size_t hash_count) {
    bf->hash_count = hash_count;
    bf->size = size;
    bitarray *ba = (bitarray *)malloc(sizeof(bitarray));
    bitarray_init(ba, size);
    bf->bits = ba;
}

// Free bloom filter by pointer.
extern void bloom_filter_free(BloomFilter* bf) {
    bitarray_free(bf->bits);
}

// Insert element into filter.
extern void bloom_filter_insert(BloomFilter* bf, const char* item) {
    if (bf == NULL || item == NULL) {
        return;
    }

    size_t item_len = strlen(item);
    uint64_t hash_seed = 0;

    for (size_t i = 0; i < bf->hash_count; ++i) {
        uint64_t hash = komihash(item, item_len, hash_seed + i);
        size_t bit_index = hash % bf->size;
        bitarray_set(bf->bits, bit_index, true);
    }
}

// Check whether element is in filter or not.
extern bool bloom_filter_exists(BloomFilter* bf, const char* item) {
    if (bf == NULL || item == NULL) {
        return false;
    }

    size_t item_len = strlen(item);
    uint64_t hash_seed = 0;

    for (size_t i = 0; i < bf->hash_count; ++i) {
        uint64_t hash = komihash(item, item_len, hash_seed + i);
        size_t bit_index = hash % bf->size;
        if (!bitarray_get(bf->bits, bit_index)) {
            return false;
        }
    }

    return true;
}
