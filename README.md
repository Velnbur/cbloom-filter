# cbloom-filter

`cbloom-filter` is a simple Bloom filter implementation in C that uses the `komihash` hash function for hashing and a bit array for storage. This project includes a Makefile for building the project and running tests.

## Table of Contents

- [Features](#features)
- [Dependencies](#dependencies)
- [Building the Project](#building-the-project)
- [Running Tests](#running-tests)
- [Usage](#usage)
- [License](#license)

## Features

- **Bloom Filter**: A probabilistic data structure that is used to test whether an element is a member of a set.
- **KOMIHASH Hash Function**: A fast and efficient 64-bit hash function.
- **Bit Array**: A simple bit array implementation for storing Bloom filter bits.

## Dependencies

This project uses the following header-only libraries:

- **KOMIHASH**: A 64-bit hash function.
  - [KOMIHASH GitHub Repository](https://github.com/avaneev/komihash)
  - LICENSE: MIT

## Building the Project

To build the project, you need to have `clang` installed. You can build the project using the provided Makefile.

### Commands

1. **Build the project**:
   ```sh
   make
   ```
   This command will compile the source files and generate the executable `bloomfilter` in the `bin` directory.

2. **Clean the build**:
   ```sh
   make clean
   ```
   This command will remove all the generated object files and the executable.

## Running Tests

To run the tests, use the following command:

```sh
make tests
```

This command will build the test executable and run the tests. The test results will be displayed in the terminal.

## Usage

Here is a simple example of how to use the Bloom filter:

```c
#include "bloomfilter.h"
#include <stdio.h>

int main() {
    BloomFilter bf;
    bloom_filter_init(&bf, 1000, 5); // Initialize with size 1000 and 5 hash functions

    // Insert elements
    bloom_filter_insert(&bf, "hello");
    bloom_filter_insert(&bf, "world");

    // Check existence
    if (bloom_filter_exists(&bf, "hello")) {
        printf("'hello' is probably in the set.\n");
    } else {
        printf("'hello' is definitely not in the set.\n");
    }

    if (bloom_filter_exists(&bf, "test")) {
        printf("'test' is probably in the set.\n");
    } else {
        printf("'test' is definitely not in the set.\n");
    }

    // Free the Bloom filter
    bloom_filter_free(&bf);
    return 0;
}
```

or compile and use testing version like this:

```sh
./bin/bloomfilter arg1 arg2 arg3 arg1
'arg1' is probably in the set.
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

---

Feel free to contribute to this project by opening issues or pull requests on GitHub.
