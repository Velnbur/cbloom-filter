CC = clang
CFLAGS = -Wall -Wextra -Wconversion -Wredundant-decls -Wshadow -Wno-unused-parameter -std=c99 -I.
LDFLAGS =

# Source files
SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

# Test files
TEST_SRCS = $(wildcard tests/*.c) $(filter-out src/main.c, $(SRCS))
TEST_OBJS = $(TEST_SRCS:.c=.o)

# Main executable
MAIN_EXEC = bloomfilter

# Test executable
TEST_EXEC = tests.bin

# Output directory
OUT_DIR = ./bin

all: $(MAIN_EXEC)

$(MAIN_EXEC): $(OBJS)
	mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) -o $(OUT_DIR)/$@ $(OBJS) $(LDFLAGS)

$(TEST_EXEC): $(TEST_OBJS)
	mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) -o $(OUT_DIR)/$@ $(TEST_OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OUT_DIR)/*.o $(OUT_DIR)/$(MAIN_EXEC) $(OUT_DIR)/$(TEST_EXEC)

tests: $(TEST_EXEC)
	$(OUT_DIR)/$(TEST_EXEC)

.PHONY: all tests clean
