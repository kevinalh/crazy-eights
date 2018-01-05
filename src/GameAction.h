#ifndef GAME_ACTION_H_
#define GAME_ACTION_H_

struct Card;
struct Player;
struct GameState;

struct GameAction;

enum moves {
	TAKE_FROM_STACK,
	PLAY_CARD,
	QUIT
};

/**
 * Constructs the action object, which goes back and forth
 * the server and the players.
 *
 * @memberof	GameAction
 */
struct GameAction *GameAction_create(struct GameAction *state);

/**
 * Serializes the object so that it can be sent to the
 * clients.
 *
 * @memberof	GameAction
 */
char *GameAction_serialize(struct GameAction *action, char *buf);

void GameAction_deserialize(struct GameAction* action);

#endif
