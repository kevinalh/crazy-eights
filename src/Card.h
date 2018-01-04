#ifndef CARD_H_
#define CARD_H_

/**
 * Enum for representing the card suites.
 */
enum suit {
	Spade, 		/**< \u2660 */
	Heart,		/**< \u2665 */
	Diamond,	/**< \u2666 */
	Club		/**< \u2663 */
};

// Forward declaration
struct Player;
struct List;

/**
 * Structure representing a card in the game.
 * 
 * @struct Card
 */
struct Card;

/**
 * List of cards structure.
 * 
 * @extends List
 * @struct CardList
 */
struct CardList;

/**
 * Makes the card be played by its owner.
 * 
 * @param[in] card
 * The card to be played.
 * 
 * @memberof Card
 * @related Player
 */
int Card_play(struct Card *card);

/**
 * Gets card number.
 * 
 * @return     Value of the card. 
 * @memberof   Card
 */
int Card_value(struct Card *card);

/**
 * Gets card suit.
 * 
 * @return     Suit of the card.
 * @memberof   Card
 */
enum suit Card_suit(struct Card *card);

/**
 * Gets a card given the set and parameters.
 * 
 * @return     The card from the set that has both the value and suit specified.
 * @memberof   Card
 */
struct Card *Card_get(struct Card **set, unsigned int value, enum suit suit);

/**
 * Prints string representation of the card.
 * Requires the buffer to have at least 2 characters to write to.
 * 
 * @param[in] card
 * The card from which we'll get the string representation.
 * @param[out] buf
 * Buffer to which the string will be written to.
 * 
 * @return     Pointer to the buffer, @p buf (for convenience).
 * @memberof   Card
 */
char *Card_string(struct Card *card, char *const buf);

/**
 * Creates a set of cards ready to use.
 *
 * @memberof   Card
 */
struct Card **Card_create_set(void);

/**
 * Frees the card set memory.
 *
 * @memberof   Card
 */
void Card_destroy_set(struct Card **card_set);

/**
 * Creates list of cards from a set already constructed
 * via Card_create_set()
 * 
 * @memberof   Card
 */
struct CardList *Card_create_list(struct Card **set);

/**
 * Sets owner for a card.
 * 
 * @memberof   Card
 */
void Card_set_owner(struct Card *card, struct Player* player);

/**
 * Gets owner of card.
 * 
 * @memberof   Card
 */
struct Player *Card_owner(const struct Card *const card);

/**
 * Creates a random stack from a set of cards.
 * @param[in] set
 * Set of cards from which the stack will be constructed.
 *   
 * @attention  Requires using srand() first. Make sure to use it only
 * once in the whole program.
 *
 * @return     Stack of cards in random order.
 * @memberof   Card
 */
struct Stack *Card_make_random_stack(struct Card **set);


#endif