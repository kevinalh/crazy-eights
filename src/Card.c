#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "Card.h"
#include "Player.h"
#include "structures/simplelist.h"
#include "structures/stack.h"

/* Club, Diamond, Heart, Spade */
static const char* suit_symbols[] = {
	"\u2660", "\u2665", "\u2666", "\u2663"
};

struct Card {
	/**
	 * Value of the card, from 1 to 13.
	 */
	unsigned int value;
	/**
	 * Suit for the card.
	 */
	enum suit suit;
	/**
	 * Player who owns the card.
	 * 
	 * Should be NULL if nobody owns it.
	 * The player should have the card in its Player::cards list.
	 */
	struct Player *owner;	
};

struct CardList {
	/**
	 * @private
	 */
	struct List list;
	/**
	 * Weird idea to make the Doxygen graph more informative.
	 * Ignore this field.
	 * @protected
	 */
	struct Card *_;
};

int Card_value(struct Card *card) {
	return card->value;
}

enum suit Card_suit(struct Card *card) {
	return card->suit;
}

struct Card *Card_get(struct Card **set, unsigned int value, enum suit suit) {
	assert(set != NULL);
	return set[(value-1)+suit];
}

char *Card_string(struct Card *card, char *const buf) {
	sprintf(buf, "%d%s", Card_value(card), suit_symbols[Card_suit(card)]);
	return buf;
}

struct Card **Card_create_set(void) {
	struct Card **card_set = malloc(52*sizeof(struct Card*));
	struct Card *new_card;
	for(int i = 1; i <= 13; ++i) {
		for(int j = Spade; j <= Club; ++j) {
			new_card = malloc(sizeof(struct Card));
			new_card->value = i;
			new_card->suit = j;
			new_card->owner = NULL;
			card_set[(i-1)*4 + j] = new_card;
		}
	}
	return card_set;
}

void Card_destroy_set(struct Card **card_set) {
	for(int i = 1; i <= 13; ++i) {
		for(int j = Spade; j <= Club; ++j) {
			free(card_set[(i-1)*4 + j]);
		}
	}
	free(card_set);
}

struct CardList *Card_create_list(struct Card **set) {
	// Notice this cast to void**:
	// https://stackoverflow.com/questions/16160799/incompatible-pointer-type-in-c
	return (struct CardList *) List_create_from((void **)set, 52);
}

struct Stack *Card_make_random_stack(struct Card **set) {
	struct Stack *stack = Stack_create();
	struct List *list = (struct List *) Card_create_list(set);
	assert(list != NULL && stack != NULL);
	struct Card *card;
	while(List_size(list) > 0) {
		card = (struct Card *)List_take_random(list);
		if(List_delete(list, card) != 1) {
			assert(0 == 1);
		}
		Stack_push(stack, card);
	}
	List_destroy(list);
	return stack;
}

void Card_set_owner(struct Card *card, struct Player* player) {
	card->owner = player;
}

struct Player *Card_owner(const struct Card *const card) {
	return card->owner;
}