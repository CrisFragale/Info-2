#include"cristian.h"

void  convertidor (float segundos, int* horas, int* minutos, int* segundos2)
{
   int i=0; 
   segundos=segundos/60;
   while(i==0)
    {
      if(segundos>60)
        {
         *(horas)=*(horas)+1;
         segundos=segundos-60;
        }else{
         *(minutos)=(int)segundos;
         segundos=(segundos-(*(minutos)));
         *(segundos2)=(int)ceil((float)segundos*60);
         i=1;
        }
    }
    return;
    
}
