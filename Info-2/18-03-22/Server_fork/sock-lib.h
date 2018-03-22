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

#define PORT 3490	/* El puerto donde se conectar�, servidor */
#define BACKLOG 10	/* Tama�o de la cola de conexiones recibidas */

int cliente_conectar (char * ip, int port);

int servidor_aceptarPedidos ( int sockfd ); /* Funci�n que crea la conexi�n*/

int servidor_abrirConexion ( int port );	/* Funci�n que acepta una conexi�n entrante*/
