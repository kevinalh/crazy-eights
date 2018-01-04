#include <stdlib.h>
#include <stdio.h>

#include "Player.h"
#include "Card.h"
#include "structures/simplelist.h"

static unsigned int players_with_default_names = 0;

/**
 * Struct representing a player in the game.
 */
struct Player {
	/**
	 * Player's name.
	 * For presentation purposes.
	 */
	char* name;
	/**
	 * Points acquired by the player so far.
	 */
	unsigned int points;
	/**
	 * List of cards owned.
	 * 
	 * It's required that the cards in this list have this
	 * pointer as their Card::owner member.
	 */
	struct CardList *cards;
};

/**
 * Another implementation would be a circular
 * double-linked list, but for simplicity this should be enough.
 */
struct PlayerList {
	/**
	 * @private
	 */
	struct List list;
	/**
	 * Weird idea to make the Doxygen graph more informative.
	 * Ignore this field.
	 * @protected
	 */
	struct Player *_;
};

struct Player *Player_create(char *name) {
	struct Player *player = malloc(sizeof(struct Player));
	if(!player) return NULL;
	player->cards = (struct CardList *)List_create();
	if(name != NULL) {
		player->name = name;
	}
	else {
		player->name = malloc(12 * sizeof(char));
		sprintf(player->name, "Player%d", players_with_default_names+1);
		players_with_default_names++;
	}
	player->points = 0;
	return player;
}

void Player_destroy(struct Player *player) {
	List_destroy((struct List *)player->cards);
	free(player);
}

int Player_take_card(struct Player *player, struct Card *card) {
	if(Card_owner(card) != NULL) return -1;
	List_add((struct List *)player->cards, card);
	Card_set_owner(card, player);
	return 0;
}

char *Player_name(struct Player *player) {
	return player->name;
}