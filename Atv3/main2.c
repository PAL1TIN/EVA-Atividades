#include <stdio.h>
#include <stdlib.h>


float dobro(float a){
 float mult = a * 2;
 return mult;
}


int main()
{
    float num;
    float res = 0;

    printf("Digite o valor: ");
    scanf("%f", &num);

    res = dobro(num);

    printf("O dobro eh: %.2f", res);
    return 0;
}
