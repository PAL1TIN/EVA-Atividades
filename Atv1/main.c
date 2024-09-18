#include <stdio.h>
#include <stdlib.h>

int soma(int a, int b){
   int r;
   r = a + b;

   return r;
}

int main()
{
    int a,b;
    int r;
    printf("Digite o valor de a:");
    scanf("%d", &a);
    printf("Digite o valor de b:");
    scanf("%d", &b);
    //r = soma(a, b);
    printf("%d", soma(a, b));
    return 0;

}
