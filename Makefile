# ---------------------------------
# GEL library Makefile
# (math / vector / matrix library only)
# ---------------------------------

CC      = gcc
CFLAGS  = -Wall -Wextra -pedantic -std=c11 -I./include
PREFIX  = /usr/local

# Link math library only
LDLIBS  = -lm

# Directories
SRC_DIR   = src
BUILD_DIR = build
TEST_DIR  = tests

# Library
LIB_NAME = libgel.a
LIB_PATH = $(BUILD_DIR)/$(LIB_NAME)

# Find all .c files under src/
SRC_FILES := $(shell find $(SRC_DIR) -name '*.c')
OBJ_FILES := $(patsubst src/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Find all tests
TEST_SOURCES := $(shell find $(TEST_DIR) -name '*.c')
TEST_BINS    := $(patsubst $(TEST_DIR)/%.c,$(BUILD_DIR)/bins/%,$(TEST_SOURCES))

.PHONY: all clean install-dev tests docs

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
# Tests (math only)
# -----------------------------
tests: $(TEST_BINS)
	@for t in $(TEST_BINS); do \
		echo ""; \
		echo "========================================="; \
		echo "Running $$t"; \
		echo ""; \
		$$t || exit 1; \
	done

$(BUILD_DIR)/bins/%: $(TEST_DIR)/%.c $(LIB_PATH)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $< $(LIB_PATH) $(LDLIBS)

# -----------------------------
# Install development symlinks
# -----------------------------
install-dev: all
	sudo rm -rf $(PREFIX)/include/gel
	sudo ln -s $(PWD)/include $(PREFIX)/include/gel
	sudo ln -sf $(PWD)/$(LIB_PATH) $(PREFIX)/lib/$(LIB_NAME)

# -----------------------------
# Documentation
# -----------------------------
docs:
	doxygen Doxyfile

# -----------------------------
# Clean
# -----------------------------
clean:
	rm -rf $(BUILD_DIR)
