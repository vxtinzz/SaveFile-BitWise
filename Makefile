CC=gcc
CFLAGS=-Wall -Wextra -O2

SRC=$(wildcard src/*.c src/*/*.c)
BIN=build\game.exe

all: build $(BIN)

$(BIN): $(SRC)
	$(CC) $(SRC) -o $(BIN) $(CFLAGS)

run: all
	$(BIN)

build:
	if not exist build mkdir build

clean:
	if exist $(BIN) del /Q $(BIN)
