#include <stdlib.h>
#include <stdio.h>

#include "Player.h"
#include "Card.h"
#include "structures/simplelist.h"

static unsigned int amount_players = 0;

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
	struct List *cards;
};

struct Player *Player_create(char *name) {
	struct Player *player = malloc(sizeof(struct Player));
	if(!player) return NULL;
	player->cards = List_create();
	if(name != NULL) {
		player->name = name;
	}
	else {
		player->name = malloc(12 * sizeof(char));
		sprintf(player->name, "Player%d", amount_players+1);
	}
	player->points = 0;
	amount_players++;
	return player;
}

void Player_destroy(struct Player *player) {
	List_destroy(player->cards);
	free(player);
}

int Player_take_card(struct Player *player, struct Card *card) {
	if(Card_owner(card) != NULL) return -1;
	List_add(player->cards, card);
	Card_set_owner(card, player);
	return 1;
}

char *Player_name(struct Player *player) {
	return player->name;
}