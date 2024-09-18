#include <stdio.h>
#include <stdlib.h>


float soma(float a, float b){
 float res1 = a + b;
 return res1;
}


int main()
{
    float num1, num2;
    float res = 0;

    printf("Digite o primeiro valor: ");
    scanf("%f", &num1);
    printf("Digite o segundo valor: ");
    scanf("%f", &num2);

    res = soma(num1, num2);

    printf("A soma eh: %.2f", res);
    return 0;
}
