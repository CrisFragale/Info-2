#include"cristian.h" //97 a 122 min
                     //65 a 92 may

int aMayuscula (char *caracter)
{
    
    if(*(caracter)>=65 && *(caracter)<=92)return(0);
    if(*(caracter)>=97 && *(caracter)<=122)
    {
        *(caracter)=*(caracter)-32;
        return (0);
        
    }else{
        return(-1);
    }
}