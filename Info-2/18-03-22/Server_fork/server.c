#include <stdio.h>
#include <unistd.h>

#include "sock-lib.h"
#include "defaults.h"


void serve(int socket, struct sockaddr_in client_addr);
int parseArg(int argc, char *argv[], char **host_name, int *port);

int main(int argc, char *argv[]){

  pid_t parent,
        child;
  char *host_name= NULL;
  int port = 0;
  int llave;
  int Cola_ID;


  int socket_up;
  int new_client;
  struct sockaddr_in my_addr,
                     their_addr;

  parseArg(argc,argv,&host_name,&port);

  parent = getpid();

  socket_up = servidor_abrirConexion ( port );

  printf("server:\n");
  printf("\tProccess ID: %d\n", parent);
  printf("\tlistening port: %d\n", port);
  printf("\tsocket n#: %d\n", socket_up);
  llave=Ftok("server.c", 'a');
  Cola_ID = msgget (llave , IPC_CREAT | 0666);



  while(socket_up > 0){
    new_client = servidor_aceptarPedidos( socket_up);
    if ( new_client > 0 ){
      child = fork();
      if ( child == 0 ){
        serve( new_client, their_addr );
      }
    }
  }

  return 0;
}
