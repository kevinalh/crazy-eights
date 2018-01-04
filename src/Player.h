#ifndef PLAYER_H_
#define PLAYER_H_

struct Card;

/**
 * Structure representing a player.
 * 
 * @struct Player
 */
struct Player;

/**
 * A list of players.
 * 
 * @extends List
 * @struct PlayerList
 */
struct PlayerList;

/**
 * Constructs a Player.
 * If the argument is NULL, uses a default name.
 * 
 * @param name
 * Name of the player. Can be NULL for default.
 * 
 * @return     New Player object.
 * 
 * @memberof   Player
 */
struct Player *Player_create(char *name);

/**
 * Player destructor.
 * 
 * @memberof   Player
 */
void Player_destroy(struct Player *player);

/**
 * Lets the player take the card.
 * Will fail if the card already has an owner.
 * 
 * @retval     0 Success
 * @retval     -1 Failure
 * 
 * @memberof   Player
 */
int Player_take_card(struct Player *player, struct Card *card);

/**
 * The player's name.
 * 
 * @return     The player's name.
 * 
 * @memberof   Player
 */
char *Player_name(struct Player *player);

#endif
