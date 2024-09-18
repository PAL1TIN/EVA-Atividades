#include <stdio.h>


int Maior(int *a, int *b, int *c){
 int maior = *a;
 if(maior > *b && maior > *c){
    return maior;
 }if (*b > maior && *b > *c){
   return *b;
 }else{
     return *c;
 }


}


int main(){
    int x,y,z,res;
    printf("Digite os 3 numeros: ");
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);
    res = Maior(&x,&y,&z);
    printf("O maior valor eh: %d", res);


return 0;
}
