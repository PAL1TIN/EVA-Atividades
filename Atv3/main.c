#include <stdio.h>
#include <stdlib.h>


float media(float a, float b){
 float res1 = (a + b)/2;
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

    res = media(num1, num2);

    printf("A media eh: %.2f", res);
    return 0;
}
