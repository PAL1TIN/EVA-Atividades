#include <stdio.h>
#include <stdlib.h>

//autores: khauan henrique e vinicius santos

typedef struct{
   int cod;
   char desc[99];
}Tipos;

typedef struct{
int num, valor, cod_serv, cod_cliente;
}Serv;





int main()
{
Tipos tipos[4];
Serv serv[30][3];



int i, j, op, cod_serv, achou, conta_tipo;
int dia, codigo_cliente, valor_serv, num_serv, valida;
int valor_inicial, valor_final, k;
char desc_serv[99];



    conta_tipo = 0;
    for(i = 0; i< 30; i++){
        for(j = 0; j < 3; j++){
            serv[i][j].num = 0;
            serv[i][j].valor = 0;
            serv[i][j].cod_serv = 0;
            serv[i][j].cod_cliente = 0;
        }
    }
    do{
        printf("Menu de opcoes\n\n");
        printf("1 - Cadastrar os tipos de servicos\n");
        printf("2 - Cadastrar os servicos prestados\n");
        printf("3 - Mostrar os servicos prestados em determinado dia\n");
        printf("4 - Mostrar os servicos prestados dentro de um intervalo de valor\n");
        printf("5 - Mostrar um relatorio geral, separado por dia\n");
        printf("6 - Finalizar\n");
        printf("Digite sua opcao: ");
        scanf("%d", &op);

        if(op < 1 || op > 6){
            printf("--Opcao invalida--\n");
        }
        if(op == 1){
            if(conta_tipo > 4){
                printf("Cadastro dos tipos de servico lotado\n\n");
            }else{
                printf("Digite o codigo do servico a ser cadastrado: ");
                scanf("%d", &cod_serv);
                achou = 0;

                for(i = 0; i <= conta_tipo; i++){
                    if (tipos[i].cod == cod_serv){
                        achou = 0;
                    }
                    if(achou == 0){
                        printf("Ja existe tipo de servico com esse codigo\n\n");
                        break;
                    }else{
                        printf("Digite a descricao do tipo de servico a ser cadastrado: ");
                        scanf("%s", desc_serv);
                        tipos[i].cod = cod_serv;
                        strcpy(tipos[i].desc, desc_serv);
                        printf("Tipo de servico cadastrado com sucesso\n\n");
                        conta_tipo++;
                        break;
                    }
                }

            }
        }

        if(op == 2){
            printf("Digite o dia em que deseja cadastrar o servico prestado: ");
            scanf("%d", &dia);
            achou = 0;
            for(j = 0; j < 3; j ++){
                if(serv[dia][j].num == 0){
                    achou = j;
                }
                if(achou == 0){
                    printf("Todos os servicos prestados neste dia foram cadastrados\n\n");

                }else{
                    printf("Digite o codigo do servico a ser cadastrado: ");
                    scanf("%d", &cod_serv);
                    valida = 0;
                    for(i = 0; i < conta_tipo; i++){
                        if(tipos[i].cod = cod_serv){
                            valida = 0;
                        }
                    }
                    if(valida = 0){
                        printf("Codigo de servico invalido\n\n");
                    }else{
                        printf("Digite o numero do servico: ");
                        scanf("%d", &num_serv);
                        printf("Digite o valor do servico: ");
                        scanf("%d", &valor_serv);
                        printf("Digite o codigo do cliente: ");
                        scanf("%d", &codigo_cliente);
                        serv[dia][achou].num = num_serv;
                        serv[dia][achou].valor = valor_serv;
                        serv[dia][achou].cod_serv = cod_serv;
                        serv[dia][achou].cod_cliente = codigo_cliente;
                        printf("Servico prestado cadastrado com sucesso\n\n");
                        break;
                    }
                }
            }
        }
        if(op == 3){
            printf("Digite o dia em que deseja consultar os servicos prestados: ");
            scanf("%d", &dia);
            achou = 0;
            for(j = 0; j < 3; j++){
                if(serv[dia][j].num != 0){
                    achou = 0;
                }
            }
            if(achou == 0){
                    printf("Nenhum servico foi prestado neste dia\n\n");
            }else{
                printf("Servicos prestado no dia %d:", dia);
            }
            for(j = 0; j < 3; j++){
                if(serv[dia][j].num != 0){
                    printf("num:%d    Valor:%d ", serv[dia][j].num, serv[dia][j].valor);
                    printf("Codigo: %d - ", serv[dia][j].cod_serv);

                    for(i = 0; i <=conta_tipo; i++){
                        if(tipos[i].cod == serv[dia][j].cod_serv){
                            printf("desc: %s ", tipos[i].desc);
                        }
                    }
                    printf("cod cliente:%d \n\n", serv[dia][j].cod_cliente);

                }
            }
        }
        if(op == 4){
            printf("Digite o valor inicial: ");
            scanf("%d", &valor_inicial);
            printf("Digite o valor final: ");
            scanf("%d", &valor_final);
            achou = 0;

            for(i = 0; i < 30; i++){
                for(j = 0; j < 3; j++){
                    if(serv[i][j].valor >= valor_inicial && serv[i][j].valor <= valor_final){
                        achou = 1;
                        printf("servico: %d    valor:%d ", serv[i][j].num, serv[i][j].valor);
                        printf("codS: %d-", serv[i][j].cod_serv);

                        for(k = 0; k<conta_tipo; k++){
                            if(tipos[k].cod == serv[i][j].cod_serv){
                                printf("%s", tipos[k].desc);
                            }
                            printf("%d\n\n", serv[i][j].cod_cliente);
                        }
                    }
                }
            }
            if(achou == 0){
                printf("nenhum servico prestado entre os valor citados\n\n");
            }
        }
        if(op == 5){
            achou = 0;
            for(i = 0; i < 30; i++){
                printf("Dia %d", i+1);
                for(j = 0; j < 3; j++){
                    if(serv[i][j].num != 0){
                        achou = 1;
                        printf(" %d %d ",serv[i][j].num, serv[i][j].valor);
                        printf("%d ", cod_serv);
                        for(k = 0; k < conta_tipo; k++){
                            if(tipos[k].cod == serv[i][j].cod_serv){
                                printf("%s\n" ,tipos[k].desc);
                            }
                            printf("%d\n", serv[i][j].cod_cliente);
                        }
                    }
                }
            }
            if(achou == 0){
                printf("nenhum servico prestado foi cadastrado\n");
            }
        }


    }while(op != 6);





























    return 0;
}
