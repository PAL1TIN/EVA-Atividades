
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// autores: khauan henrique e vinicius santos

typedef struct {
    int cod;
    char desc[99];
} Tipos;

typedef struct {
    int num;
    float valor;
    int cod_serv;
    int cod_cliente;
} Serv;

void zerarServ(Serv *serv) {
    serv->num = 0;
    serv->valor = 0.0;
    serv->cod_cliente = 0;
    serv->cod_serv = 0;
}

void cadastrarServ(Serv serv[30][3], int *conta_tipo, Tipos *tipos) {
    char desc_serv[99];
    int achou, cod_serv;

    printf("Digite o codigo do servico a ser cadastrado: ");
    scanf("%d", &cod_serv);
    achou = 0;

    for (int i = 0; i < *conta_tipo; i++) {
        if (tipos[i].cod == cod_serv) {
            achou = 1;
            break;
        }
    }

    if (achou == 1) {
        printf("Ja existe tipo de servico com esse codigo\n\n");
    } else {
        printf("Digite a descricao do servico: ");
        scanf(" %[^\n]s", desc_serv);
        tipos[*conta_tipo].cod = cod_serv;
        strcpy(tipos[*conta_tipo].desc, desc_serv);
        printf("Tipo de servico cadastrado com sucesso\n\n");
        (*conta_tipo)++;
    }
}

void cadastrarServPrestado(Serv serv[30][3], int *conta_serv, Tipos *tipos, int conta_tipo) {
    int dia, achou = -1, num_serv, cod_cliente, valida;
    float valor_serv;
    int cod_serv;

    printf("Digite o dia em que deseja cadastrar o servico: ");
    scanf("%d", &dia);

    for (int j = 0; j < 3; j++) {
        if (serv[dia][j].num == 0) {
            achou = j;
            break;
        }
    }

    if (achou == -1) {
        printf("Todos os servicos neste dia foram cadastrados\n");
    } else {
        printf("Digite o codigo do servico a ser cadastrado: ");
        scanf("%d", &cod_serv);
        valida = 0;

        for (int i = 0; i < conta_tipo; i++) {
            if (tipos[i].cod == cod_serv) {
                valida = 1;
                break;
            }
        }

        if (valida == 0) {
            printf("Codigo de servico invalido\n");
        } else {
            printf("Digite o numero do servico: ");
            scanf("%d", &num_serv);
            printf("Digite o valor do servico: ");
            scanf("%f", &valor_serv);
            printf("Digite o codigo do cliente: ");
            scanf("%d", &cod_cliente);

            serv[dia][achou].num = num_serv;
            serv[dia][achou].valor = valor_serv;
            serv[dia][achou].cod_serv = cod_serv;
            serv[dia][achou].cod_cliente = cod_cliente;

            printf("O servico prestado foi cadastrado com sucesso\n");
            (*conta_serv)++;
        }
    }
}

int main() {
    Tipos tipos[4];
    Serv serv[30][3];
    int i, j, op, achou, conta_tipo = 0, conta_serv = 0;
    int dia, valor_inicial, valor_final, k;

    // Inicializando todos os serviços com zero
    for (i = 0; i < 30; i++) {
        for (j = 0; j < 3; j++) {
            zerarServ(&serv[i][j]);
        }
    }

    do {
        printf("Menu de opcoes\n\n");
        printf("1 - Cadastrar os tipos de servicos\n");
        printf("2 - Cadastrar os servicos prestados\n");
        printf("3 - Mostrar os servicos prestados em determinado dia\n");
        printf("4 - Mostrar os servicos prestados dentro de um intervalo de valor\n");
        printf("5 - Mostrar um relatorio geral, separado por dia\n"); 
        printf("6 - Finalizar\n");
        printf("Digite sua opcao: ");
        scanf("%d", &op);

        if (op < 1 || op > 6) {
            printf("--Opcao invalida--\n");
        }

        switch(op) {
            case 1:
                if (conta_tipo >= 4) {
                    printf("Cadastro dos tipos de servico lotado\n\n");
                } else {
                    cadastrarServ(serv, &conta_tipo, tipos);
                }
                break;

            case 2:
                cadastrarServPrestado(serv, &conta_serv, tipos, conta_tipo);
                break;

            case 3:
                printf("Digite o dia em que deseja consultar os servicos prestados: ");
                scanf("%d", &dia);
                achou = 0;
                for (j = 0; j < 3; j++) {
                    if (serv[dia][j].num != 0) {
                        achou = 1;
                        printf("Servicos prestados no dia %d:\n", dia);
                        printf("num:%d    Valor:%.2f ", serv[dia][j].num, serv[dia][j].valor);
                        printf("Codigo: %d - ", serv[dia][j].cod_serv);

                        for (i = 0; i < conta_tipo; i++) {
                            if (tipos[i].cod == serv[dia][j].cod_serv) {
                                printf("desc: %s ", tipos[i].desc);
                                break;
                            }
                        }
                        printf("cod cliente: %d \n\n", serv[dia][j].cod_cliente);
                    }
                }
                if (achou == 0) {
                    printf("Nenhum servico foi prestado neste dia\n\n");
                }
                break;

            case 4:
                printf("Digite o valor inicial: ");
                scanf("%d", &valor_inicial);
                printf("Digite o valor final: ");
                scanf("%d", &valor_final);
                achou = 0;

                for (i = 0; i < 30; i++) {
                    for (j = 0; j < 3; j++) {
                        if (serv[i][j].valor >= valor_inicial && serv[i][j].valor <= valor_final) {
                            achou = 1;
                            printf("servico: %d    valor:%.2f ", serv[i][j].num, serv[i][j].valor);
                            printf("codS: %d - ", serv[i][j].cod_serv);

                            for (k = 0; k < conta_tipo; k++) {
                                if (tipos[k].cod == serv[i][j].cod_serv) {
                                    printf("%s ", tipos[k].desc);
                                    break;
                                }
                            }
                            printf("%d\n\n", serv[i][j].cod_cliente);
                        }
                    }
                }
                if (achou == 0) {
                    printf("Nenhum servico prestado entre os valores citados\n\n");
                }
                break;

            case 5:
                achou = 0;
                for (i = 0; i < 30; i++) {
                    printf("Dia %d\n", i+1);
                    for (j = 0; j < 3; j++) {
                        if (serv[i][j].num != 0) {
                            achou = 1;
                            printf(" %d %.2f ", serv[i][j].num, serv[i][j].valor);
                            printf("%d ", serv[i][j].cod_serv);

                            for (k = 0; k < conta_tipo; k++) {
                                if (tipos[k].cod == serv[i][j].cod_serv) {
                                    printf("%s\n", tipos[k].desc);
                                    break;
                                }
                            }
                            printf("%d\n", serv[i][j].cod_cliente);
                        }
                    }
                }
                if (achou == 0) {
                    printf("Nenhum servico prestado foi cadastrado\n");
                }
                break;
        }
    } while (op != 6);

    return 0;
}