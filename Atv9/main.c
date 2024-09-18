#include <stdio.h>
#include "ContaBancaria.h"

int main(int argc, char *argv[])
{
   ContaBancaria conta1;
   Inicializa(&conta1, 91888, 300.00);
   printf ("\n Antes da movimentacao:\n" );
   Imprime(conta1);
   Deposito(&conta1, 50.00);
   Saque(&conta1, 70.00);
   Deposito(&conta1, 200);
   printf("\nDepois da movimentacao:\n");
   Imprime(conta1);
       return 0;
}

