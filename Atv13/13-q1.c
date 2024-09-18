#include <stdio.h>
#include <string.h>
// Vinícius Santos e Khauan Henrique 

typedef struct {
    int num;
    float saldo;
    char nome[100];
} Conta;

Conta conta[15]; 
int posi = 0;    


void criarConta() {
    int num_conta;
    int achou = 0;

    if (posi >= 15) {
        printf("Todas as contas já foram criadas\n");
    } else {
        printf("Digite a conta a ser cadastrada: ");
        scanf("%d", &num_conta);
        
        
        for (int i = 0; i < posi; i++) {
            if (num_conta == conta[i].num) {
                achou = 1;
                break;
            }
        }

        if (achou) {
            printf("Já existe conta cadastrada com esse número.\n");
        } else {
            conta[posi].num = num_conta;

            printf("Digite o nome do cliente: ");
            scanf("%99s", conta[posi].nome);

            printf("Digite o saldo do cliente: ");
            scanf("%f", &conta[posi].saldo);

            printf("Conta cadastrada com sucesso\n\n");
            posi++;
        }
    }
}


void consultarNome() {
    char nome_cliente[100]; 
    int achou = 0;

    printf("Digite o nome do cliente a ser consultado: \n");
    scanf("%99s", nome_cliente); 

    for (int i = 0; i < posi; i++) {
        if (strcmp(conta[i].nome, nome_cliente) == 0) {
            printf("Conta: %d - Saldo: %.2f R$\n", conta[i].num, conta[i].saldo);
            achou = 1;
        }
    }

    if (!achou) {
        printf("Não existe conta cadastrada com esse cliente\n");
    }
}


void excluirCtMenorSaldo() {
    int i;
    int achou = 0;
    float menor_saldo;

    if (posi == 0) {
        printf("Nenhuma conta foi cadastrada\n");
        return;
    }

    
    menor_saldo = conta[0].saldo;
    achou = 1;

    for (i = 1; i < posi; i++) {
        if (conta[i].saldo < menor_saldo) {
            menor_saldo = conta[i].saldo;
        }
    }

    for (i = 0; i < posi; i++) {
        if (conta[i].saldo == menor_saldo) {
            
            for (int j = i; j < posi - 1; j++) {
                conta[j] = conta[j + 1];
            }
            posi--; 
            printf("Conta excluída com sucesso\n\n");
            return;
        }
    }
}


int main() {
    int i, op;

    
    for (i = 0; i < 15; i++) {
        conta[i].num = 0;
        strcpy(conta[i].nome, "");
        conta[i].saldo = 0.0;
    }

    do {
        printf("MENU DE OPÇÕES");
        printf("\n1 - CADASTRAR CONTAS");
        printf("\n2 - VISUALIZAR TODAS AS CONTAS DE UM DETERMINADO CLIENTE");
        printf("\n3 - EXCLUIR CONTA DE MENOR SALDO");
        printf("\n4 - SAIR");
        printf("\nQUAL A SUA OPÇÃO: ");
        scanf("%d", &op);

        if (op < 1 || op > 4) {
            printf("Opção inválida\n");
        }

        switch (op) {
            case 1:
                criarConta();
                break;

            case 2:
                consultarNome();
                break;

            case 3:
                excluirCtMenorSaldo();
                break;
        }
    } while (op != 4);

    return 0;
}