

#include <stdio.h>
#include <string.h>


typedef struct {
    char nome[200];
    char end[200];
    float precoMedio;
    char tipcom[100];
} Restaurante;

Restaurante receberRestaurante() {
    Restaurante r;
    printf("Digite o nome do restaurante: ");
    scanf("%s", r.nome);
    printf("Digite o endere�o do restaurante: ");
    scanf("%s", r.end);
    printf("Digite o pre�o m�dio do restaurante: ");
    scanf("%f", &r.precoMedio);
    printf("Digite o tipo de comida do restaurante: ");
    scanf("%s", r.tipcom);
    return r;
}


void listarRestaurantes(Restaurante restaurantes[], int num) {
    printf("\nista de Restaurantes\n");
    for (int i = 0; i < num; i++) {
        printf("Restaurante %d:\n", i + 1);
        printf("Nome: %s\n", restaurantes[i].nome);
        printf("Endere�o: %s\n", restaurantes[i].end);
        printf("Pre�o m�dio: %.2f\n", restaurantes[i].precoMedio);
        printf("Tipo da comida: %s\n", restaurantes[i].tipcom);
        printf("\n");
    }
}

int main() {
    Restaurante restaurantes[5];

    for (int i = 0; i < 5; i++) {
        printf("\nCadastro do Restaurante %d\n", i + 1);
        restaurantes[i] = receberRestaurante();
    }

    listarRestaurantes(restaurantes, 5);

    return 0;
}

