#include "palabras.h"
void leepalabra(FILE *fp, char *pal){
	while(strcmp(pal, "fin")!=0){
		fprintf(fp, "%s; ", pal);
		scanf("%s", pal);
	}
}