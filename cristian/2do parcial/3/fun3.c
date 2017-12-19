#include "sock-lib.h"
#include "cristian2.h"

int fun3(nodo_t* ptr_h)
{
	int sockfd; 
	tema_t dato;

	sockfd = cliente_conectar ("127.0.0.1", 1515);

	while(ptr_h!=NULL)
	{
		if(write (sockfd, &ptr_h->datos.infoTema , sizeof (tema_t)) == -1)
			{
				perror("Error escribiendo mensaje en socket");
				exit (1);
			}
		ptr_h=ptr_h->next;
	}
	printf("sali");
	dato.codigo=-1;
	if(write (sockfd, &dato , sizeof (tema_t)) == -1)
			{
				perror("Error escribiendo mensaje en socket");
				exit (1);
			}
	
	close(sockfd);
	return 0;
}
 
