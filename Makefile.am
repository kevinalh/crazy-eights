DATA_STRUCTURES = src/structures/stack.h src/structures/stack.c \
	src/structures/simplelist.h src/structures/simplelist.c

GAME_STRUCTURES = src/Player.c src/Card.c src/Player.h src/Card.h $(DATA_STRUCTURES)

bin_PROGRAMS = crazyeights
crazyeights_SOURCES = $(GAME_STRUCTURES) src/crazyeights.c src/menuprinters.c src/serverclient.c

TESTS = check_Player

check_PROGRAMS = check_Player

check_Player_SOURCES = $(GAME_STRUCTURES) test/check_Player.c
check_Player_CFLAGS = @CHECK_CFLAGS@
check_Player_LDADD = @CHECK_LIBS@