# 1 "factorial.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "factorial.c"
int factorial (int a){
 int resultado=1;
 int i;
 if (a==0){
  resultado=1;
 }
 else{
  for (i=a; i > 0; i--){
   resultado=resultado*i;
  }
 }
 return resultado;
}
