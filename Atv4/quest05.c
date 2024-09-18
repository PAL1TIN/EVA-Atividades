#include <stdio.h>


int Menor(int *a, int *b){
 int menor = *a;
 if(menor < *b){
    return menor;
 }else{
   return *b;
 }


}


int main(){
    int x,y,res;
    printf("Digite os dois numeros: ");
    scanf("%d", &x);
    scanf("%d", &y);
    res = Menor(&x,&y);
    printf("O menor valor eh: %d", res);


return 0;
}
