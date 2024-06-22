/*Dado o vetor V, definido por:
int V[100];
Faça um programa que execute os seguintes passos
a) preencha todos os elementos do vetor com o valor 71;
b) mostre os 100 valores contidos no vetor, uns ao lado dos outros
c) preencha o vetor com os números inteiros 1, 2, 3..., 100;
d) mostre os 100 valores contidos no vetor, uns embaixo dos outros
e) preencha o vetor: com 1 em V[i], caso i seja um quadrado perfeito, e com 0 nos demais casos.
f) mostre os 100 valores contidos no vetor, uns ao lado dos outros*/

#include <stdio.h>
#include <math.h>

int main() {
    int v[100];

    for (int i =0; i<100; i++) {
        v[i] = 71;
        printf("%i ", v[i]);
    }
    printf("\n");

    for (int i=1; i <= 100; i++) {
        v[i] = i;
        printf("%i \n", v[i]);
    }
    printf("\n");

     for (int i = 0; i < 100; i++) {
        int raiz = sqrt(v[i]);
        if (raiz * raiz == v[i])
            v[i] = 1;
        else
            v[i] = 0;
        printf("%i ", v[i]);
    }
    printf("\n");
}