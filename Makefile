CC = gcc
CFLAGS = -Iinclude -Wall -Wextra
LDFLAGS = -Llib -lraylib -lm -ldl -lpthread -lGL -lX11

SRC_DIR = src
OBJ_DIR = build/obj
BIN = build/main

SRC = $(shell find $(SRC_DIR) -name '*.c')
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# def target
all: $(BIN)

# link last binary
$(BIN): $(OBJ)
	@mkdir -p $(dir $@)
	$(CC) $^ -o $@ $(LDFLAGS)

# compile .c to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf build/obj $(BIN)

.PHONY: all clean
