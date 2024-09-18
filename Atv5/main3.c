#include <stdio.h>
#include <stdlib.h>

void neg(float *vetor, int num){
    int i;
    int contN = 0;
    int somaP = 0;
    for(i=0;i<num;i++){
        if(vetor[i] < 0){
            contN++;
        }else{
                somaP = somaP + vetor[i];
            }

        }
    printf("A quantidade de numeros negativos eh: %d", contN);
    printf("\nA soma dos numeros positivos eh: %d", somaP);
    }


int main(){
    float vet[10];
    int i;
    printf("Digite 10 numeros:");
    for(i=0;i<10;i++){
        scanf("%f", &vet[i]);
    }
    neg(&vet, 10);
    return 0;
}
