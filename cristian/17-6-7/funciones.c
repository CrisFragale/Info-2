int GenerarNumero () 
{
    
 char validacion=1;
 int i=0,aux;
 
 srand(time(NULL));
 if(generado!=NULL)
 {
 
    while(validacion!=0)
    aux=rand()% (int)pow(10,MAX_INGRESOS);
    separar(completo,generado, MAX_INGRESOS);
    
 }else{
    printf("puntero no valido\n");
    return (0);
}
 
}
