#include <stdio.h>
#include <stdlib.h>

void par(int *vetor, int num){
    int i;
    printf("\nNumeros Pares: ");
    for(i=0;i<num;i++){
        if(vetor[i] % 2 == 0 ){
            printf("- %d ", vetor[i]);
        }
    }
}

void contpar(int *vetor, int num){
  int i;
  int cont=0;
  for(i = 0; i < num; i++){
    if(vetor[i]%2==0){
        cont++;
    }
  }
  printf("\nA quant de num par eh: %d\n", cont);
}
void impar(int *vetor, int num){
    int i;
    printf("\nNumeros Impares: ");
    for(i=0;i<num;i++){
        if(vetor[i] % 2 == 1 ){
            printf("- %d ", vetor[i]);
        }
    }
}

void contimpar(int *vetor, int num){
  int i;
  int cont=0;
  for(i = 0; i < num; i++){
    if(vetor[i]%2==1){
        cont++;
    }
  }
  printf("\nA quant de num impar eh: %d\n", cont);
}




int main()
{
    int vet[6];
    int i;

    for(i = 0; i < 6; i++){
        printf("Digite um numero: ");
        scanf("%d", &vet[i]);
    }

    par(&vet,6);
    contpar(&vet, 6);
    impar(&vet,6);
    contimpar(&vet, 6);

    return 0;
}
