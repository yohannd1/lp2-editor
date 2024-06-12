CC := gcc
OUTPUT := out.com
SRC := $(wildcard src/*.c)

INCFLAGS := $(shell pkg-config --cflags gtk4)
LIBFLAGS := $(shell pkg-config --libs gtk4)
CFLAGS := $(INCFLAGS) $(LIBFLAGS) -Wall -std=c99 -pedantic

run: $(OUTPUT)
	./$(OUTPUT)

$(OUTPUT): $(SRC)
	$(CC) -o $@ $(SRC) $(CFLAGS)

.PHONY: run
