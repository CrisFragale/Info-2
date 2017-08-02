#include"cristian.h"

int main (void)
{
 unsigned int a,b,c,d;
 printf("Inicialice la bolsa\n");
 scanf("%d",&d);
 srand(d);
 a=rand()%7;
 b=rand()%7;
 c=rand()%7;
 printf("a=%d \n b=%d \n c=%d \n",a,b,c);
 return (0);

}