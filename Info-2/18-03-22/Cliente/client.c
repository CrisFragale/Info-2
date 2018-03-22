#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "sock-lib.h"
#include "defaults.h"

int main(int argc, char *argv[]){

  int socket = cliente_conectar (HOST_NAME, PORT);
  fcntl(socket,F_SETFL,O_NONBLOCK);



  close(fd);
  close(socket);

  return -1;
}
