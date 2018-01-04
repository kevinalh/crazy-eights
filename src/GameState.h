#include "Card.h"
#include "Player.h"

/**
 * Structure representing the current state of the game.
 * Includes functions for modifying it.
 * 
 * @struct	GameState
 */
struct GameState;

/**
 * Default constructor.
 * 
 * @return		New GameState structure with default values.
 * @memberof	GameState
 */
struct GameState *GameState_create();

/**
 * Gets card on top of the stack.
 *
 * @return		Card on top of the stack.
 * @memberof	GameState
 */
struct Card *GameState_top_card(struct GameState *state);
