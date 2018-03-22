/*Realice una función que reciba un vector de strings ​, ​identifique cuales de esos strings solo
contienen caracateres numéricos (es aconsejable hacer una función aparte que haga el
análisis del string para informar si son todos caracteres numéricos). De todos los string que
solo posean caracteros numéricos calcule la suma y devuelva dicho valor.
Su prototipo será:​ int sumador( char ** vector, int tam );
Para probar la función utilice los argumentos del main como vector de strings.
*/

#include "cristian.h"

 int main (int argc, char **argv)
 {
   int suma=0;
   if(argc<2)
   {
   	printf ("no se han insgresado strings");
   	return 0;
   }
   suma= sumador(argv, (argc-1));
   printf ("la suma dio %d \n",suma);

 } 
