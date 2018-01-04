#ifndef CARD_H_
#define CARD_H_

#include "structures/simplelist.h"

enum suit {
	Spade, Heart, Diamond, Club
};

// Forward declaration
struct Player;
struct Card;

/**
 * Make a player play a certain card.
 * 
 * @memberof Card
 */
int play(struct Card *card, struct Player *player);

/**
 * Gets card number.
 * 
 * @memberof Card
 */
int Card_value(struct Card *card);

/**
 * Gets card suit.
 * 
 * @memberof Card
 */
enum suit Card_suit(struct Card *card);

/**
 * Gets a card given the set and parameters.
 * 
 * @memberof Card
 */
struct Card *Card_get(struct Card **set, unsigned int value, enum suit suit);

/**
 * Prints string representation of the card.
 * Requires the buffer to have at least 2 characters to write to.
 * 
 * @memberof Card
 */
char *Card_string(struct Card *card, char *const buf);

/**
 * Creates a set of cards ready to use.
 *
 * @memberof Card
 */
struct Card **Card_create_set(void);

/**
 * Frees the card set memory.
 *
 * @memberof Card
 */
void Card_destroy_set(struct Card **card_set);

/**
 * Creates list of cards from a set already constructed
 * via Card_create_set()
 * 
 * @memberof Card
 */
struct List *Card_create_list(struct Card **set);

/**
 * Sets owner for a card.
 * 
 * @memberof Card
 */
void Card_set_owner(struct Card *card, struct Player* player);

/**
 * Gets owner of card.
 * 
 * @memberof Card
 */
struct Player *Card_owner(const struct Card *const card);

/**
 * Creates a random stack from a set of cards.
 * Requires using srand() first.
 *
 * @memberof Card
 */
struct Stack *Card_make_random_stack(struct Card **set);


#endif