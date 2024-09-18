#include <stdio.h>

float Media(float *a, float *b){


return (*a + *b) / 2;

}


int main(){
float x, y, res;
printf("digite 2 valores para obter a media:\n");
scanf("%f", &x);
scanf("%f", &y);
res = Media(&x, &y);
printf("a media eh : %.2f", res);



return 0;
}
