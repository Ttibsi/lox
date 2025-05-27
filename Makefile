CC := clang++
CFLAGS := -Wall -Wextra -Wimplicit-fallthrough -g --std=c++23
LDFLAGS := -stdlib=libc++
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
	$(CC) $< -c -MMD -MP -o $@ $(CFLAGS) $(LDFLAGS) $(san) 

$(BIN): $(objects) build/main.o
	$(CC) $^ -o $@ $(LDFLAGS) $(san)

.PHONY: clean
clean:
	rm -rf build
	if [ -f $(BIN) ]; then rm $(BIN); fi
	if [ -f core ]; then rm core; fi
