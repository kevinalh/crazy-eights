#ifndef SERVER_H
#define SERVER_H

/**
* Maximum size of queue for server.
*/
static const int QUEUE_MAX = 7;

/**
* Returns a socket file descriptor that can be used by the server.
* This socket is being listened to, so just accept() it.
*/
int initialize_server(void);

#endif