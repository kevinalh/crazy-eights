#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>

#include "serverclient.h"
#include "menuprinters.h"
#include "Card.h"
#include "Player.h"

#include "structures/stack.h"

int main(void) {
	print_menu_main();
	int option = 0;
	while(option != 1 && option != 2) {
		int res = fscanf(stdin, "%d", &option);
		if(res == EOF) {
			fprintf(stderr, "Error reading option.\n");
			exit(1);
		}
		if(res != 1 || (option != 1 && option != 2)) {
			fprintf(stderr, "Try again. ");
		}
	}
	// Seed.
	srand(time(NULL));
	struct Card **card_set = Card_create_set();
	struct Stack *stack = Card_make_random_stack(card_set);
	/*
	struct Card *tmp_card;
	while(Stack_top(stack) != NULL) {
		tmp_card = (struct Card *)Stack_pop(stack);
	}
	*/
	// Freeing memory
	Stack_destroy(stack);
	Card_destroy_set(card_set);
	// First we get a server socket file descriptor, properly listened to.
	// int sockfd = initialize_server();
	return 0;
}