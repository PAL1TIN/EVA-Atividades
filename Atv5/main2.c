#include <stdio.h>
#include <stdlib.h>

void trinta(int *vetor, int num){
    int i, qtd=0;
    for(int i=0; i<num; i++){
        if(vetor[i]==30){
        qtd++;
        printf("A posicao eh: %d\n", i+1);
        }
    }
}

int main(){
    int vet[15], i;
    printf("Digite 15 numeros:");
    for(i=0;i<15;i++){
        scanf("%d", &vet[i]);
    }
    trinta(&vet, 15);
    return 0;
}
