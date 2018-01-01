#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <signal.h>

#include "serverclient.h"
#include "menuprinters.h"
#include "Card.h"
#include "Player.h"

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
	// First we get a server socket file descriptor, properly listened to.
	int sockfd = initialize_server();
	struct Card** card_set = NULL;
	Card_create(&card_set);
	char tmp[15];
	return 0;
}