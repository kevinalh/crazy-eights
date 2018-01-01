CC = gcc
CFLAGS = -Wall -g -Wextra -Wpedantic -Wshadow -Wcast-qual -Wstrict-prototypes -Wmissing-prototypes
SRC = src
BIN = bin
OBJ = obj

default: crazyeights

crazyeights: serverclient.o crazyeights.o menuprinters.o simplelist.o Card.o
	$(CC) -g -o $(BIN)/crazyeights $(OBJ)/serverclient.o $(OBJ)/crazyeights.o $(OBJ)/menuprinters.o $(OBJ)/Card.o

%.o: $(SRC)/%.c
	$(CC) -g $< $(CFLAGS) -c -o $(OBJ)/$@

run: crazyeights
	$(BIN)/crazyeights