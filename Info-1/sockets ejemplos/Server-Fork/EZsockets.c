#include "EZsockets.h"


int ezsock_connect(const char *remote_host, int port ){

	int	sockfd;
	// Se utiliza para convertir el nombre del host a su dirección IP
	struct hostent *he;
	// dirección del server donde se conectará
	struct sockaddr_in their_addr;

	//  Convertimos el nombre del host a su dirección IP
	he = gethostbyname((const char *) remote_host);
	if ( he == NULL ) {
		perror("gethostbyname");
		exit(1);
	}

 // Creamos el socket
 	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if ( sockfd < 0) {
		perror("socket");
		return -1;
	}

 	// Establecemos their_addr con la direccion del server
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(port);
	their_addr.sin_addr = *((struct in_addr *)he->h_addr);
	bzero(&(their_addr.sin_zero), 8);

 	// Intentamos conectarnos con el servidor
	int ret_val = connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr));
	if ( ret_val  < 0 )	{
		perror("connect");
		return -1;
	}
	return sockfd;
}


int ezsock_open( struct sockaddr_in * my_addr, int port ) {
	// socket auxiliar
	int	sockaux;
	int	ret;

	// Crea un socket y verifica si hubo algún error
	sockaux = socket(AF_INET, SOCK_STREAM, 0);
	if ( sockaux  < 0 )	{
		perror("socket");
		return -1;
	}

	//  Asignamos valores a la estructura my_addr
	//familia de sockets INET para UNIX
	my_addr->sin_family = AF_INET;
	// convierte el entero formato PC a entero formato network
	my_addr->sin_port = htons(port);
	// automaticamente usa la IP local
	my_addr->sin_addr.s_addr = INADDR_ANY;
	bzero(&(my_addr->sin_zero), 8);

	// Con la estructura sockaddr_in completa, se declara en el Sistema que este
	// proceso escuchará pedidos por la IP y el port definidos
	ret = bind(sockaux, (struct sockaddr *) my_addr, sizeof(struct sockaddr));
	if ( ret < 0)	{
		perror("bind");
		return -1;
	}
	//  Habilitamos el socket para recibir conexiones, con una cola de conexiones
	// en espera que tendrá como máximo el tamaño especificado en BACKLOG
	ret = listen(sockaux, BACKLOG);
	if ( ret < 0 ) {
		perror("listen");
		return -1;
  }
	return sockaux;
}

int ezsock_accept( int sockfd, struct sockaddr_in *their){
	int newfd; 	// Por este socket duplicado del inicial se transaccionará
	struct sockaddr_in their_addr;  // Contendra la direccion IP y número de puerto	del cliente
	unsigned int sin_size = sizeof(struct sockaddr_in);

	// Se espera por conexiones
	newfd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
	if ( their != NULL ){
		memcpy(their,&their_addr,sin_size);
	}
	if (newfd < 0) {
		perror("accept");
		return -1;
	}
	else {
		return newfd;
	}
}
