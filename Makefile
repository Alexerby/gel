# Minimal GEL library Makefile with tests support

CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11 -I./include

# Directories
SRC_DIR = src
BUILD_DIR = build
TEST_DIR = tests
PREFIX = /usr/local

# Library
LIB_NAME = libgel.a
LIB_PATH = $(BUILD_DIR)/$(LIB_NAME)

# Find all .c files under src/ (recursively)
SRC_FILES := $(shell find $(SRC_DIR) -name '*.c')
OBJ_FILES := $(patsubst src/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

.PHONY: all clean install-dev tests

# -----------------------------
# Default target: build library
# -----------------------------
all: $(LIB_PATH)

# Compile object files from source
$(BUILD_DIR)/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Archive static library
$(LIB_PATH): $(OBJ_FILES)
	@mkdir -p $(BUILD_DIR)
	ar rcs $@ $^

# -----------------------------
# Tests
# -----------------------------
# Collect test sources recursively
TEST_SOURCES := $(shell find $(TEST_DIR) -name '*.c')

# Turn tests/foo/bar.c → build/bins/foo/bar
TEST_BINS := $(patsubst $(TEST_DIR)/%.c,$(BUILD_DIR)/bins/%,$(TEST_SOURCES))

# Run all tests
tests: $(TEST_BINS)
	@for t in $(TEST_BINS); do \
		echo ""; \
	    echo "========================================="; \
	    echo "Running $$t"; \
		echo ""; \
	    $$t || exit 1; \
	done

# Build each test binary from its matching .c file
$(BUILD_DIR)/bins/%: $(TEST_DIR)/%.c $(LIB_PATH)
	@mkdir -p $(@D)   # ensure nested dirs exist
	$(CC) $(CFLAGS) -o $@ $< $(LIB_PATH) -lm

# -----------------------------
# Install development symlinks
# -----------------------------
install-dev: all
	sudo rm -rf $(PREFIX)/include/gel
	sudo ln -s $(PWD)/include $(PREFIX)/include/gel
	sudo ln -sf $(PWD)/$(LIB_PATH) $(PREFIX)/lib/$(LIB_NAME)

# -----------------------------
# Clean
# -----------------------------
clean:
	rm -rf $(BUILD_DIR)
