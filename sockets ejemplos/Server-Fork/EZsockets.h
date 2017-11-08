#ifndef __EZSOCKETS_H__
#define __EZSOCKETS_H__

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <netdb.h>

// Tamaño de la cola de conexiones recibidas
#define BACKLOG 50

int ezsock_connect(const char *remote_host, int port);
int ezsock_open( struct sockaddr_in * my_addr, int port );
int ezsock_accept( int sockfd, struct sockaddr_in *their);


#endif
