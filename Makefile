# Minimal Makefile for Gel library development. 
# Currently just adapted for dev environment.

CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11 -I./include

# Directories
SRC_DIR = src
BUILD_DIR = build

# Static library
LIB_NAME = libgel.a
LIB_PATH = $(BUILD_DIR)/$(LIB_NAME)

# Find all .c files under src/ (including nested folders)
SRC_FILES = $(shell find $(SRC_DIR) -name '*.c')

# Object files go in build/, preserving folder structure
OBJ_FILES = $(patsubst src/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))
PREFIX = /usr/local

.PHONY: all clean install-dev

# build lib
all: $(LIB_PATH)

# compile object files
$(BUILD_DIR)/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# archive static library
$(LIB_PATH): $(OBJ_FILES)
	@mkdir -p $(BUILD_DIR)
	ar rcs $@ $^

# symlink headers & library to /usr/local for fast development
install-dev: all

	# remove old symlink
	sudo rm -rf $(PREFIX)/include/gel

	# symlink the include folder
	sudo ln -s $(PWD)/include $(PREFIX)/include/gel

	# symlink the static library
	sudo ln -sf $(PWD)/$(LIB_PATH) $(PREFIX)/lib/$(LIB_NAME)

# clean the build
clean:
	rm -rf $(BUILD_DIR)
