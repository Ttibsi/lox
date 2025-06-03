CC := clang
CFLAGS := -Wall -Wextra -Wimplicit-fallthrough -g
BIN := lox

ifeq (0, 1)
	san := -fsanitize=address,undefined
endif

sources := $(filter-out src/main.c,$(wildcard src/*.c))
objects := $(patsubst src/%.c,build/%.o,$(sources))

.PHONY: all
all:
	bear -- $(MAKE) $(BIN)

build:
	mkdir build

build/%.o: src/%.c | build
	$(CC) $< -c -MMD -MP -o $@ $(CFLAGS) $(san) 

$(BIN): $(objects) build/main.o
	$(CC) $^ -o $@ $(san)

.PHONY: clean
clean:
	rm -rf build
	if [ -f $(BIN) ]; then rm $(BIN); fi
	if [ -f core ]; then rm core; fi
