CC := g++
CFLAGS := -Wall -Wextra -Wimplicit-fallthrough -g -std=c++23
BIN := lox

ifeq (0, 1)
	san := -fsanitize=address,undefined
endif

sources := $(filter-out src/main.cpp,$(wildcard src/*.cpp))
objects := $(patsubst src/%.cpp,build/%.o,$(sources))

.PHONY: all
all:
	bear -- $(MAKE) $(BIN)

build:
	mkdir build

build/%.o: src/%.cpp | build
	$(CC) $< -c -MMD -MP -o $@ $(CFLAGS) $(san)

$(BIN): $(objects) build/main.o
	$(CC) $^ -o $@ $(san)
