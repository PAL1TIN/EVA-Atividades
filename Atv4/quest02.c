#include <stdio.h>

int ParImpar(int *a){

    if(*a % 2 == 0){
        return 1;
    } else{
        return 2;
    }
}


int main(){
 int num;
 char res;
 printf("Digite um valor: ");
 scanf("%d", &num);
 res = ParImpar(&num);
 if(res == 1){
    printf("O numero eh par ");
 }else{
  printf("O numero eh impar ");
 }

return 0;
}
