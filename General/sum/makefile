# Compiler and flags
CC = gcc
CFLAGS = -Wall -I../include

# Output library directory
LIB_DIR ?= ../lib  # check LIB_DIR is exist or not
LIB_SUM = $(LIB_DIR)/libsum.a

# Source and object files
SRC = sum.c
OBJ = $(SRC:.c=.o)

# Build static library
all: $(LIB_DIR) $(LIB_SUM)

# Create library directory if folder is not exist
$(LIB_DIR):
	mkdir -p $(LIB_DIR)

# Build static library
$(LIB_SUM): $(OBJ)
	ar rcs $@ $^

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJ)

.PHONY: all clean
