# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude

# Directories
LIB_DIR = lib
SUM_DIR = sum
MINUS_DIR = minus
BUILD_DIR = build

# Libraries
LIB_SUM = $(LIB_DIR)/libsum.a
LIB_MINUS = $(LIB_DIR)/libminus.so

# All target
all: $(LIB_DIR) $(LIB_SUM) $(LIB_MINUS) main

# Create library directory
$(LIB_DIR):
	mkdir -p $(LIB_DIR)

# Build static library for sum
$(LIB_SUM):
	$(MAKE) -C $(SUM_DIR) LIB_DIR=../$(LIB_DIR)

# Build shared library for minus
$(LIB_MINUS):
	$(MAKE) -C $(MINUS_DIR) LIB_DIR=../$(LIB_DIR)

# Build main program
main: main.o $(LIB_SUM) $(LIB_MINUS)
	$(CC) $(CFLAGS) -o main main.o -L$(LIB_DIR) -lsum -lminus -Wl,-rpath=$(LIB_DIR)

# Compile main.o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

# Clean all build files
clean:
	rm -f main main.o
	$(MAKE) -C $(SUM_DIR) clean
	$(MAKE) -C $(MINUS_DIR) clean
	rm -rf $(LIB_DIR)

.PHONY: all clean

