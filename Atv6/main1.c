#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int pecas;
  float preco;
} Venda;

Venda totaldevenda(Venda a, Venda b){
    Venda total;
    total.pecas = a.pecas+b.pecas;
return total;
}

Venda totaldevenda2(Venda a, Venda b){
    Venda total2;
    total2.preco = (a.preco * a.pecas) + (b.preco * b.pecas);
return total2;
}


int main()
{   Venda vendaA, vendaB, total, total2;

    printf("Digite a quantidade do produto A: ");
    scanf("%d",&vendaA.pecas);
    printf("Digite o preco do produto A: ");
    scanf("%f", &vendaA.preco);



    printf("E digite a quantidade do produto B: ");
    scanf("%d", &vendaB.pecas);
    printf("Digite o preco de B: ");
    scanf("%f", &vendaB.preco);

     total = totaldevenda(vendaA, vendaB);
    printf("A quantidade de produtos eh: %d", total.pecas);


    total2 = totaldevenda2(vendaA, vendaB);

    printf("\nA soma dos produtos eh: %.2f", total2.preco);



    return 0;
}
