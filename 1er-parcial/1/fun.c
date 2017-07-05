#include "cristian.h"

int strInvertir( char * str )
{
    char aux[250];
    int largo;
    int i,j,verificacion=0;
    if((str)==NULL)return 1;
    largo=strlen(str);
    strcpy(aux,str);
    for (i=0,j=largo;i<largo;i++,j--)
    {
    	str[i]=aux[j-1];
    	if(str[i]==aux[j-1])
    	{
           verificacion++;
    	}
    } 
    if(verificacion==(i))return 1;
    return 0;    
}

 
