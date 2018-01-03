CC = gcc
CFLAGS = -g -Wall -Wextra -Wpedantic -Wshadow -Wcast-qual -Wstrict-prototypes -Wmissing-prototypes -Werror -DNDEBUG
SRC = src
BIN = bin
OBJ = obj
PROGRAM = crazyeights
FILES = $(PROGRAM) Card Player menuprinters serverclient structures/simplelist structures/stack
SRC_FILES = $(addprefix $(SRC)/,$(addsuffix .c,$(FILES)))
OBJ_FILES = $(addprefix $(OBJ)/,$(addsuffix .o,$(FILES)))

default: $(BIN)/$(PROGRAM)

$(OBJ)/%.o: $(SRC)/%.c
	mkdir -p $(OBJ)/structures
	$(CC) $< $(CFLAGS) -c -o $@

$(BIN)/$(PROGRAM): $(OBJ_FILES)
	$(CC) -o $(BIN)/$(PROGRAM) $(OBJ_FILES)

run: default
	$(BIN)/$(PROGRAM)

clean:
	$(RM) $(OBJ_FILES) $(BIN)/$(PROGRAM)
	if [ -d "$(OBJ)/structures" ]; then rmdir $(OBJ)/structures; fi

.PHONY: clean run