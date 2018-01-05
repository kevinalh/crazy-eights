#ifndef GAME_STATE_H_
#define GAME_STATE_H_

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
struct Card *GameState_top_card(const struct GameState *const state);

/**
 * Pops card off the top of the stack.
 *
 * @return		Card on top of the stack.
 * @memberof	GameState
 */
struct Card *GameState_pop_card(struct GameState *const state);

/**
 * Gets the current player playing.
 *
 * @return		Current player.
 * @memberof	GameState
 */
struct Player *GameState_current_player(const struct GameState *const state);

/**
 * Moves to the next player.
 *
 * @memberof	GameState
 */
void GameState_next_player(struct GameState *const state);

#endif
