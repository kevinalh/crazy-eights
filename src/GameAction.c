#include "Player.h"
#include "Card.h"
#include "GameState.h"

struct GameTurn {
	struct Card *card_played;
	struct Player *last_player;
	struct Player *new_player;
};

struct GameTurn *GameTurn_create(struct GameState *state) {

}

/**
 * Serializes the object so that it can be sent to the
 * clients.
 *
 * @memberof	GameTurn
 */
char *GameTurn_serialize(struct GameTurn *turn);
