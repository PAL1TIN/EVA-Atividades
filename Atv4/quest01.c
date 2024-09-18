#include <stdio.h>
#include <math.h>
//Escreva uma função que faça a soma de dois valores e imprima o resultado da
//operação;

 int soma(int *a, int *b){

 return *a + *b;

 }


int main(){
int x, y, res;
printf("digite 2 valores para somar:\n");
scanf("%d", &x);
scanf("%d", &y);
res = soma(&x, &y);
printf("o resultado eh: %d", res);





return 0;
}
