#include <stdlib.h>

#include "Card.h"
#include "Player.h"
#include "structures/stack.h"

struct GameState {
	/**
	 * @protected
	 * Players in the game.
	 */
	struct PlayerList *players;
	/**
	 * @protected
	 * How many players there are in the game.
	 */
	unsigned int amount_players;
	/**
	 * @protected
	 * Set of cards in an ordered fashion.
	 */
	struct Card **card_set;
	/**
	 * @protected
	 * Stack of cards.
	 */
	struct Stack *stack;
};

struct GameState *GameState_create() {
	struct GameState *state = malloc(sizeof(struct GameState));
	state->amount_players = 0;
	return state;
}

struct Player *GameState_current_player(const struct GameState *const state) {
	return List_current((struct List *)state->players);
}

void GameState_next_player(struct GameState *const state) {
	List_iterate((struct List *)state->players);
}
