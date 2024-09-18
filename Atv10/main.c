#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Autores: Khauan Henrique e Vinicius Santos

typedef struct {
    int num;
    float saldo;
    char nome[20];
} Conta;

int main() {
    int i, op, posi = 0, achou, num_conta;
    float menor_saldo;
    char nome_cliente[20];

    Conta conta[15];

    for (i = 0; i < 15; i++) {
        conta[i].num = 0;
        strcpy(conta[i].nome, "");
        conta[i].saldo = 0.0;
    }

    do {
        printf("Menu de opcoes:\n");
        printf("1 - Cadastrar contas\n");
        printf("2 - Visualizar todas as contas de determindo cliente\n");
        printf("3 - Excluir conta de menor saldo\n");
        printf("4 - Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &op);

        if (op < 1 || op > 4) {
            printf("---Opcao invalida---\n");
            continue;
        }


        if(op == 1){
                if (posi >= 15) {
                    printf("Todas as contas ja foram cadastradas\n\n");
                } else {
                    achou = 0;
                    printf("Digite o numero da conta a ser incluida: ");
                    scanf("%d", &num_conta);

                    for (i = 0; i < posi; i++) {
                        if (num_conta == conta[i].num) {
                            achou = 1;
                            break;
                        }
                    }
                    if (achou == 1) {
                        printf("Ja existe conta com esse numero\n");
                    } else {
                        conta[posi].num = num_conta;
                        printf("Digite o nome do cliente: ");
                        scanf("%s", conta[posi].nome); // Sem o &
                        printf("Digite o saldo do cliente: ");
                        scanf("%f", &conta[posi].saldo);
                        printf("Conta cadastrada com sucesso\n\n");
                        posi++;
                    }
                }

            }

            if(op == 2){
                    printf("Digite o nome do cliente a ser consultado: ");
                scanf("%s", nome_cliente);
                achou = 0;
                for (i = 0; i < posi; i++) {
                    if (strcmp(conta[i].nome, nome_cliente) == 0) {
                        printf("Conta: %d Saldo: %.2f\n\n", conta[i].num, conta[i].saldo);
                        achou = 1;
                    }
                }
                if (achou == 0) {
                    printf("Nao existe conta cadastrada para esse cliente\n\n");
                }

            }

            if(op == 3){
                if (posi == 0) {
                    printf("Nenhuma conta foi cadastrada\n\n");
                } else {
                    menor_saldo = conta[0].saldo;
                    achou = 0;
                    int pos_menor = 0;
                    for (i = 1; i < posi; i++) {
                        if (conta[i].saldo < menor_saldo) {
                            menor_saldo = conta[i].saldo;
                            pos_menor = i;
                            achou = 1;
                        }
                    }

                    for (i = pos_menor; i < posi - 1; i++) {
                        conta[i] = conta[i + 1];
                    }
                    printf("Conta excluida com sucesso\n\n");
                    posi--;
                }
            }



    } while (op != 4);

    return 0;
}
