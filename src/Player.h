#ifndef PLAYER_H_
#define PLAYER_H_

struct Player;
struct Card;

/**
* Constructs a player. If the argument is NULL, uses a
* default name.
*/
struct Player *Player_create(char *name);

/**
* Player destructor.
*/
void Player_destroy(struct Player *player);

/**
* Lets the player take the card. Returns 1 on success.
* Will fail if the card already has an owner.
*/
int Player_take_card(struct Player *player, struct Card *card);

#endif