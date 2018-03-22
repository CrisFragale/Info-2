#include <QCoreApplication>
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void senall (int);

int main(void)
{
    int a;
    a=getpid();
    printf("PID %d",a);
    signal(SIGUSR1, senall);
    scanf("%d",&a);
    return(0);

}

void senall (int)
{
            printf("llego la señallllll \n");
            exit(0);

}
