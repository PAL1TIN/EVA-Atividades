#include <stdio.h>

int Maior(int *a, int *b){
 int maior = *a;
 if(maior > *b){
    return maior;
 }else{
   return *b;
 }


}


int main(){
    int x,y,res;
    printf("Digite os dois numeros: ");
    scanf("%d", &x);
    scanf("%d", &y);
    res = Maior(&x,&y);
    printf("O maior valor eh: %d", res);


return 0;
}
