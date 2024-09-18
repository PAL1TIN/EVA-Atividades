#include <stdio.h>


int Maior(int *vet, int num){
    int i;
    int dia, maior = 0;
    for ( i = 0; i < num; i++) {
        if (maior < vet[i]) {
            maior = vet[i];
        }
    }
    return maior;
}
int Dia(int *vet, int num){
    int i;
    int dia = 0, maior;
    for ( i = 0; i < num; i++) {
        if (maior < vet[i]) {
            maior = vet[i];
            dia = 0;
            dia = i+1;
        }
    }
    return dia;
}

    int main() {
    int vet[28];
    int maior = 0;
    int i;
    int dia;

    for ( i = 0; i < 28; i++) {
        printf("Digite a venda do dia %d: ", i+1);
        scanf("%d", &vet[i]);
    }
    maior = Maior(&vet, 28);
    dia = Dia(&vet, 28);
    printf("A maior venda foi %d no dia %d", maior ,dia);
    return 0;
}
