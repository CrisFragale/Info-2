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

#define PORT 3490	/* El puerto donde se conectará, servidor */
#define BACKLOG 10	/* Tamaño de la cola de conexiones recibidas */

int cliente_conectar (char * ip, int port);

int servidor_aceptarPedidos ( int sockfd ); /* Función que crea la conexión*/

int servidor_abrirConexion ( int port );	/* Función que acepta una conexión entrante*/
