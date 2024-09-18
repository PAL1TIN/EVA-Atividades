#include <stdio.h>
#include <stdlib.h>

int maior (int x, int y){
 int max;
 if( x > y){
    max= x;
 } else if ( y > x ){
     max=y;
   } else {
        printf("Os numeros sao iguais!");
     }
 return max;
}





int main()
{
    int num1, num2;
    int maio;
    printf("Valor do primeiro num: ");
    scanf("%d", &num1);
    printf("Valor do segundo num: ");
    scanf("%d", &num2);
    maio = maior(num1,num2);
    printf("O maior numero eh: %d", maio);
    return 0;
}
