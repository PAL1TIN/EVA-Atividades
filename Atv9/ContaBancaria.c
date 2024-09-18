#include <stdio.h>
#include "ContaBancaria.h"

void Inicializa(ContaBancaria* conta, int numero, double saldo){
    if (conta == NULL) {
        printf("Erro: Conta não pode ser NULL.\n");
        return;
    }
    conta->numero = numero;
    conta->saldo = saldo;
}


void Deposito(ContaBancaria* conta, double valor){
    if (conta == NULL) {
        printf("Erro: Conta não pode ser NULL.\n");
        return;
    }
}

void Saque(ContaBancaria* conta, double valor){
    if (conta == NULL) {
        printf("Erro: Conta não pode ser NULL.\n");
        return;
    }
    if (valor <= 0) {
        printf("O valor do saque deve ser positivo.\n");
        return;
    }
    if (valor > conta->saldo) {
        printf("Saldo insuficiente.\n");
        return;
    }
    conta->saldo -= valor;

}
void Imprime(ContaBancaria conta){
    printf("Numero da Conta: %d\n", conta.numero);
    printf("Saldo: %.2f\n", conta.saldo);
    return;
}

