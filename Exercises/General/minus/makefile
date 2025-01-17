# Compiler and flags
CC = gcc
CFLAGS = -Wall -I../include -fPIC

# Output library directory
LIB_DIR ?= ../lib
LIB_MINUS = $(LIB_DIR)/libminus.so

# Source and object files
SRC = minus.c
OBJ = $(SRC:.c=.o)

# Build shared library
all: $(LIB_DIR) $(LIB_MINUS)

# Create library directory if folder is not exist
$(LIB_DIR):
	mkdir -p $(LIB_DIR)

# Build shared library
$(LIB_MINUS): $(OBJ)
	$(CC) -shared -o $@ $^

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJ)

.PHONY: all clean
