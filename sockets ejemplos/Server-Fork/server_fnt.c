#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "EZsockets.h"
#include "defaults.h"



void serve(int socket, struct sockaddr_in client_addr){
  pid_t child = getpid();
  char buffer[64];
  char file_name[100] = "DB/";
  printf("child:\n");
  printf("\tProccess ID: %d\n", child);
  printf("\tsocket n#: %d\n", socket);

  read(socket,buffer,150);
  printf("\tClient requested: %s\n", buffer);
  strncat(file_name,buffer,100);

  int db = open(file_name, O_RDONLY);
  if (db < 0 ){
    perror(file_name);
    exit(-1);
  }
  int rd = read(db,buffer,64);
  while( rd > 0 ){
    send(socket, buffer, 64,0);
    rd = read(db,buffer,64);
  }
  close(rd);
  close(socket);
  sleep(10);
  printf("\tchild %d exit()\n", child);
  exit(0);
}

const char *localhost_str=HOST_NAME;
int parseArg(int argc, char *argv[], char **host_name, int *port){
  if (argc == 1){
    *host_name=(char*)localhost_str;
    *port = PORT;
  }
  else if ( argc == 2 ){
    *host_name = argv[1];
    *port = PORT;
  }
  else if (argc == 3 ){
    *host_name = argv[1];
    *port = atoi(argv[2]);
  }
  return 0;
}
