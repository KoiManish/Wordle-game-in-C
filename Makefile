CC = gcc

CFLAGS = -Wall -Wextra -std=gnu11 -g

TARGET = build/wordle

SRCS = main.c game.c io.c words.c
OBJS = $(SRCS:%.c=build/%.o)

BUILD_DIR = build

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

build/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

run: all
	./$(TARGET)

.PHONY: all clean run
