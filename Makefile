# ----------------------------
# Makefile para Windows
# Compilação de todos .c em src/
# Saída: build/game.exe
# ----------------------------

CC=gcc
CFLAGS=-Wall -Wextra -O2

# Pega todos os .c dentro de src e subpastas diretas
SRC=$(wildcard src/*.c src/*/*.c)
BIN=build\game.exe


# ---- Compilar ----
all: build $(BIN)

$(BIN): $(SRC)
	$(CC) $(SRC) -o $(BIN) $(CFLAGS)


# ---- Rodar ----
run: all
	$(BIN)


# ---- Criar pasta build caso não exista ----
build:
	if not exist build mkdir build


# ---- Limpar ----
clean:
	if exist $(BIN) del /Q $(BIN)
