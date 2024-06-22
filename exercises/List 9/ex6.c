/*Escreva um programa que determine o maior valor de um vetor bem como sua posição no vetor (índice).
Tal processamento deve ser feito em uma função que recebe o vetor (do tipo float) e sua capacidade, e
“retorna” o maior elemento e sua posição.
void max_vetor(float vet[], int tam, float *pMax, int *pIndice);*/

#include <stdio.h>

void max_vetor(float vet[], int tam, float *pMax, int *pIndice) {
    *pMax = vet[0];
    *pIndice = 0;

    for (int i = 1; i < tam; i++) {
        if (vet[i] > *pMax) {
            *pMax = vet[i];
            *pIndice = i;
        }
    }
}

int main() {
    int tam;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tam);

    float vet[tam];
    printf("Informe os elementos do vetor: ");
    for (int i = 0; i < tam; i++) {
        scanf("%f", &vet[i]);
    }

    float max;
    int indice;
    max_vetor(vet, tam, &max, &indice);

    printf("O maior valor do vetor é %.2f e está na posição %d.\n", max, indice);

    return 0;
}
