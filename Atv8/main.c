#include <stdio.h>

typedef struct{
  char nome[300];
  int quant;
  float preco;
  int ret;
}Venda;


Venda cadastro(Venda venda[], int num){
  int i;
    for(i = 0; i < num; i++){
      printf("Digite o nome do produto: ");
      scanf("%s", &venda[i].nome);
      printf("Digite a quantidade de produtos: ");
      scanf("%d",&venda[i].quant);
      printf("Digite o preço do produto: ");
      scanf("%f", &venda[i].preco);
      printf("Quantos produtos voce quer retirar?  ");
      scanf("%d",&venda[i].ret);
     }
 
}

Venda mostre(Venda v){
  v.quant -= v.ret;
  printf("O nome do produto eh: %s\n", v.nome);
  printf("A quantidade de produtos restantes eh: %d\n", v.quant);
  printf("O total dos precos dos produtos retirados: %.2f\n", v.preco*v.ret);
}

int main(void) {
  Venda venda[3];
  int i;
  cadastro(venda,3);
  printf("\n");
  for(i=0;i<3;i++){
  mostre(venda[i]);
  printf("-----------------------------------------------------\n");
  }
  
  return 0;
}