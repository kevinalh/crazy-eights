#include <stdlib.h>
#include <stdio.h>

#include "Player.h"
#include "Card.h"
#include "structures/simplelist.h"

static unsigned int amount_players = 0;

struct Player {
	char* name;
	unsigned int points;
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
	if(Card_owner(card) != NULL) return 0;
	List_add(player->cards, card);
	Card_set_owner(card, player);
	return 1;
}