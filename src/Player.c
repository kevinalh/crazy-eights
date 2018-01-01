#include "Player.h"
#include "Card.h"
#include "simplelist.h"

struct Player {
	char* name;
	unsigned int points;
	struct List *cards;
};

struct 
