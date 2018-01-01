#include <stdlib.h>
#include <stdio.h>

#include "Card.h"
#include "Player.h"

/* Club, Diamond, Heart, Spade */
static const char* suit_symbols[] = {
	"\u2660", "\u2665", "\u2666", "\u2663"
};

struct Card {
	int value;
	enum suit suit;
	struct Player *owner;	
};

int Card_value(struct Card *card) {
	return card->value;
}


enum suit Card_suit(struct Card *card) {
	return card->suit;
}

void Card_string(struct Card *card, char *buf) {
	sprintf(buf, "%d%s", Card_value(card), suit_symbols[Card_suit(card)]);
}

void Card_create(struct Card ***card_set) {
	*card_set = malloc(52*sizeof(struct Card*));
	struct Card *new_card;
	for(int i = 1; i <= 13; ++i) {
		for(int j = Spade; j <= Club; ++j) {
			new_card = malloc(sizeof(struct Card));
			new_card->value = i;
			new_card->suit = j;
			new_card->owner = NULL;
			*((*card_set) + (i-1)*4 + j) = new_card;
		}
	}
}

void Card_set_owner(struct Card *card, struct Player* player) {
	card->owner = player;
}

struct Player *Card_owner(struct Card *card) {
	return card->owner;
}