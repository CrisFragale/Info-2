#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int i, j;
	for (i = 0; i < argc; i++){
		for (j = 0; argv[i][j]!='\0'; j++){			
			printf("%c", argv[i][j]);
		}
		printf("\n");
	}
	return 0;
}