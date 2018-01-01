#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>

#include "serverclient.h"

static char* server_port = "3490";

int initialize_server(void) {
	int sockfd;
	struct addrinfo hints, *servinfo, *p;

	// Sets the hints addrinfo structure
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	// Error-checking variable
	int rv;

	// Initialize the servinfo linked list
	if((rv = getaddrinfo(NULL, server_port, &hints, &servinfo)) == -1) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		exit(1);
	}

	// Argument for sockopt
	int yes = 1;

	// Bind to some of the possible addrinfo structures
	for(p = servinfo; p != NULL; p = p->ai_next) {
		if((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
			perror("socket");
			continue;
		}
		if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
			perror("setsockopt");
			exit(1);
		}
		if(bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			perror("bind");
			continue;
		}
		break;
	}

	// We don't need this structure anymore since we've already
	// binded and got a socket file descriptor.
	freeaddrinfo(servinfo);

	// If not even one of the possible addrinfo structures worked.
	if(p == NULL) {
		fprintf(stderr, "Failure to bind.");
		exit(1);
	}

	// Listen to the socket.
	if(listen(sockfd, QUEUE_MAX) == -1) {
		perror("listen");
		exit(1);
	}
	return sockfd;
}