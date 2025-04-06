#include <stdio.h>

#include "bloomfilter.h"

int main(int argc, const char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string1> <string2> ... <stringN>\n", argv[0]);
        return 1;
    }

    size_t size = 1000; // Example size for the bloom filter
    size_t hash_count = 3; // Example number of hash functions
    BloomFilter bf;
    bloom_filter_init(&bf, size, hash_count);

    for (int i = 1; i < argc - 1; ++i) {
        bloom_filter_insert(&bf, argv[i]);
    }

    const char* last_item = argv[argc - 1];
    bool exists = bloom_filter_exists(&bf, last_item);
    if (exists) {
        printf("The item '%s' might be in the bloom filter.\n", last_item);
    } else {
        printf("The item '%s' is definitely not in the bloom filter.\n", last_item);
    }

    bloom_filter_free(&bf);
    return 0;
}
