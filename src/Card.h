#ifndef CARD_H
#define CARD_H

enum suit {
	Spade, Heart, Diamond, Club
};

// Forward declaration
struct Player;
struct Card;

/**
* Make a player play a certain card.
*/
int play(struct Card *card, struct Player *player);

/**
* Gets card number.
*/
int Card_value(struct Card *card);

/**
* Gets card suit.
*/
enum suit Card_suit(struct Card *card);

/**
* Prints string representation of the card.
* Requires the buffer to have at least 2 characters to write to.
*/
void Card_string(struct Card *card, char *buf);

/**
* Creates a set of cards ready to use.
*/
void Card_create(struct Card ***card_set);

/**
* Sets owner for a card.
*/
void Card_set_owner(struct Card *card, struct Player* player);

/**
* Gets owner of card.
*/
struct Player *Card_owner(struct Card *card);

#endif