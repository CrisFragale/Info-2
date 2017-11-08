#include "server.h"


int cliente_conectar (char * ip, int port)
{

	int	sockfd;
	struct hostent *he;	/* Se utiliza para convertir el nombre del host a su
				direcci�n IP */
	struct sockaddr_in their_addr;  /* direcci�n del server donde se conectar� */

	/* Convertimos el nombre del host a su direcci�n IP */
	if ((he = gethostbyname ((const char *) ip)) == NULL)
	{
		herror("Error en gethostbyname");
		exit(1);
	}
 
/* Creamos el socket */
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("Error en creaci�n de socket");
		exit(1);
	}

/* Establecemos their_addr con la direccion del server */
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(port);
	their_addr.sin_addr = *((struct in_addr *)he->h_addr);
	bzero(&(their_addr.sin_zero), 8);

/* Intentamos conectarnos con el servidor */
	if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1)
	{
		perror("Error tratando de conectar al server");
		exit(1);
	}
	return sockfd;
}


int servidor_abrirConexion ( int port )
{
	int	sockaux;	/*socket auxiliar*/
	int	aux; 		/*variable auxiliar*/
	struct sockaddr_in my_addr;
	
	/*Crea un socket y verifica si hubo alg�n error*/
	if ((sockaux = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
	{
		fprintf(stderr, "Error en funci�n socket. C�digo de error %s\n", strerror(sockaux));
		return -1;
	}

/* Asignamos valores a la estructura my_addr */

	my_addr.sin_family = AF_INET;		/*familia de sockets INET para UNIX*/
	my_addr.sin_port = htons(port);	/*convierte el entero formato PC a
						entero formato network*/
	my_addr.sin_addr.s_addr = INADDR_ANY;	/* automaticamente usa la IP local */
	bzero(&(my_addr.sin_zero), 8);		/* rellena con ceros el resto de la
						 estructura */

	/* Con la estructura sockaddr_in completa, se declara en el Sistema que este
	 proceso escuchar� pedidos por la IP y el port definidos*/
	if ( (aux = bind (sockaux, (struct sockaddr *) &my_addr, sizeof(struct sockaddr))) == -1)
	{
		fprintf(stderr, "Error en funci�n bind. C�digo de error %s\n", strerror(aux));
		return -1;
	}
	/* Habilitamos el socket para recibir conexiones, con una cola de conexiones
	en espera que tendr� como m�ximo el tama�o especificado en BACKLOG*/
	if ((aux = listen (sockaux, BACKLOG)) == -1)
	{
		fprintf(stderr, "Error en funci�n listen. C�digo de error %s\n", strerror(aux));
		return -1;
        }
	return sockaux;
}

int servidor_aceptarPedidos ( int sockfd )
{
	int newfd; 	/* Por este socket duplicado del inicial se transaccionar�*/
        struct sockaddr_in their_addr;  /* Contendra la direccion IP y n�mero de
					puerto	del cliente */
	unsigned int sin_size = sizeof(struct sockaddr_in);

	/*Se espera por conexiones ,*/
	if ((newfd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size)) == -1)
	{
		fprintf(stderr, "Error en funci�n accept. C�digo de error %s\n", strerror(newfd));
		return -1;
	}
	else
	{
		printf  ("server:  conexion desde:  %s\n", inet_ntoa(their_addr.sin_addr));
		return newfd;
	}
}
