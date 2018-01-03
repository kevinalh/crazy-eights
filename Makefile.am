DATA_STRUCTURES = src/structures/stack.h src/structures/stack.c \
	src/structures/simplelist.h src/structures/simplelist.c

GAME_STRUCTURES = src/Player.c src/Card.c DATA_STRUCTURE

bin_PROGRAMS = crazyeights
crazyeights_SOURCES = src/crazyeights.c src/menuprinters.c src/serverclient.c GAME_STRUCTURES

TESTS = check_Player

check_PROGRAMS = check_Player

check_Player_SOURCES = test/check_Player.c GAME_STRUCTURES
check_Player_CFLAGS = @CHECK_CFLAGS@
check_Player_LDADD = @CHECK_LIBS@