/*1 - Dado um vetor de inteiros, preencha-o com somatórios.
O programa deve permitir que o usuário indique a quantidade de elementos do vetor (que deve ser
maior que zero). Use uma função para preencher o vetor com o valor dos somatórios acumulados dos
índices dos vetores, conforme ilustrado abaixo:
0 1 2 3 4 5 6 7 8 9 10 ...
0 1 3 6 10 15 21 28 36 45 55 ...
Após preencher o vetor com os somatórios, mostre os valores dos elementos na tela, também usando
uma função. Use VLA, tanto na declaração do vetor quanto nas funções. Sugestões de protótipos para
as funções*/

#include <stdio.h>

void fill_array(int n, int vet[n]) {
    int soma = 0;
    for (int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            soma = soma + j;;
        }
        vet[i] = soma;
    }
}

void show_array(int n, int vet[n]) {
    for (int i=0; i<n; i++) {
        printf("%i \n", vet[i]);
    }
}

int main() {
    int n, vet[n];
    printf("Informe a quantidade de elementos: ");
    scanf("%i", &n);
    fill_array(n, vet);
    show_array(n, vet);
}