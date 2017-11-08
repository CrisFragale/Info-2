#include <stdio.h>
#include <unistd.h>

#include "EZsockets.h"
#include "defaults.h"


void serve(int socket, struct sockaddr_in client_addr);
int parseArg(int argc, char *argv[], char **host_name, int *port);

int main(int argc, char *argv[]){

  pid_t parent,
        child;
  char *host_name= NULL;
  int port = 0;

  int socket_up;
  int new_client;
  struct sockaddr_in my_addr,
                     their_addr;

  parseArg(argc,argv,&host_name,&port);
  parent = getpid();
  socket_up = ezsock_open(&my_addr, port);

  printf("server:\n");
  printf("\tProccess ID: %d\n", parent);
  printf("\tlistening port: %d\n", port);
  printf("\tsocket n#: %d\n", socket_up);

  while(socket_up > 0){
    new_client = ezsock_accept( socket_up, &their_addr);
    if ( new_client > 0 ){
      child = fork();
      if ( child == 0 ){
        serve( new_client, their_addr );
      }
    }
  }

  return 0;
}
