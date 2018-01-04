#ifndef PLAYER_H_
#define PLAYER_H_

struct Card;
struct Player;

/**
 * Constructs a player. If the argument is NULL, uses a
 * default name.
 * 
 * @memberof Player
 */
struct Player *Player_create(char *name);

/**
 * Player destructor.
 * 
 * @memberof Player
 */
void Player_destroy(struct Player *player);

/**
 * Lets the player take the card. Returns 1 on success.
 * Will fail if the card already has an owner.
 * 
 * @memberof Player
 */
int Player_take_card(struct Player *player, struct Card *card);

/**
 * Returns the player's name.
 * 
 * @memberof Player
 */
char *Player_name(struct Player *player);

#endif