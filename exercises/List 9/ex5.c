/*Escreva uma função que recebe um vetor e sua capacidade como parâmetros e precisa “retornar” o
maior e o menor valores do vetor.
void max_min(int vet[], int tam, int *pMin, int *pMax);*/

#include <stdio.h>

void max_min(int vet[], int tam, int *pMin, int *pMax) {
    *pMin = *pMax = vet[0];
    for (int i = 1; i < tam; i++) {
        if (vet[i] < *pMin) {
            *pMin = vet[i];
        }
        if (vet[i] > *pMax) {
            *pMax = vet[i];
        }
    }
}

int main() {
    int tam;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tam);

    int vet[tam];
    printf("Informe os elementos do vetor: ");
    for (int i = 0; i < tam; i++) {
        scanf("%d", &vet[i]);
    }

    int min, max;
    max_min(vet, tam, &min, &max);

    printf("Valor mínimo: %d\n", min);
    printf("Valor máximo: %d\n", max);

    return 0;
}
