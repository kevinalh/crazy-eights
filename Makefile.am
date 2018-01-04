DATA_STRUCTURES = src/structures/stack.h src/structures/stack.c \
	src/structures/simplelist.h src/structures/simplelist.c

GAME_STRUCTURES = src/Player.c src/Card.c src/GameState.c src/Player.h src/Card.h src/GameState.h \
	$(DATA_STRUCTURES)

bin_PROGRAMS = crazyeights
crazyeights_SOURCES = $(GAME_STRUCTURES) src/crazyeights.c src/menuprinters.c src/serverclient.c

TESTS = test/check_Player test/check_GameState

check_PROGRAMS = test/check_Player test/check_GameState

test_check_Player_SOURCES = $(GAME_STRUCTURES) test/check_Player.c
test_check_Player_CFLAGS = @CHECK_CFLAGS@
test_check_Player_LDADD = @CHECK_LIBS@

test_check_GameState_SOURCES = $(GAME_STRUCTURES) test/check_GameState.c
test_check_GameState_CFLAGS = @CHECK_CFLAGS@
test_check_GameState_LDADD = @CHECK_LIBS@