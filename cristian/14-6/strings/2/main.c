#include"cristian.h"

int main (void)
{
	char frase[500];
	char buff[20];
	strcpy(frase,"");
	printf("Ingrese palabras que luego se uniran en una frase \n");
	scanf("%s",buff);
	while(strcmp(buff,"fin"))
	{
       strcat(frase,buff);
       strcat(frase," ");
       scanf("%s",buff);
       if((500-strlen(frase)<(strlen(buff)+1)))strcpy(buff,"fin");
	}
	printf("%s \n",frase);
}


