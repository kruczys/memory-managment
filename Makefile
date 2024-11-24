CC = gcc
CFLAGS = -Wall -Wextra -g

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/malloc.c \
       $(SRC_DIR)/free.c \
       $(SRC_DIR)/realloc.c \
       $(SRC_DIR)/calloc.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

TARGET = $(BIN_DIR)/main

$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean
