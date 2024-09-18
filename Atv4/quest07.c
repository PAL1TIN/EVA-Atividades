#include <stdio.h>

int Par(int *a){
 if(*a % 2 == 0){
    return 1;
 }else{
   return 2;
 }
}




int main(){
 int x, res;
 printf("Digite UM numero par: ");
 scanf("%d", &x);
 res = Par(&x);
 if(res == 1){
    printf("Esse numero eh par ");
 }else{
   printf("Esse numero eh impar ");
 }




return 0;
}
