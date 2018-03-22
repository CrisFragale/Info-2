#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "EZsockets.h"
#include "defaults.h"

int main(int argc, char *argv[]){

  int socket = ezsock_connect(HOST_NAME, PORT);
  fcntl(socket,F_SETFL,O_NONBLOCK);

  char buffer[64];
  strcpy(buffer,argv[1]);
  printf("Requesting: %s\n",buffer);
  write(socket, buffer, 64);

  int fd = open(argv[1],O_WRONLY | O_CREAT | O_TRUNC, 0666);
  int rd = recv(socket,buffer,64,0);



  while( rd == 64 ){
    write(fd,buffer,64);
    rd = recv(socket,buffer,64,0);
  }

  close(fd);
  close(socket);

  return -1;
}
