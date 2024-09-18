#include <stdio.h>

int Fatorial(int *a){
int res = 1 ;
  for(int i = 1; i <= *a; i++){
    res *= i;
  }

return res;
}


int main(){
int x, res;
printf("digite um valor para descobrir o fatorial:\n");
scanf("%d", &x);
res = Fatorial(&x);
printf("o resultado eh: %d", res);



return 0;
}
