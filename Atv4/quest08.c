#include <stdio.h>

int Somatorio(int *a){
int res = 0;
  for(int i = 1; i <= *a; i++){
    res += i;
  }

return res;
}


int main(){
int x, res;
printf("digite um valor para descobrir o somatorio:\n");
scanf("%d", &x);
res = Somatorio(&x);
printf("o resutado eh: %d", res);






return 0;
}
