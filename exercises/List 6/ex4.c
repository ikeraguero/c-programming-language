/*screva uma função que recebe um vetor v, sua capacidade n e uma chave de busca. A função também
recebe um vetor que vai armazenar os índices em que a chave se encontra em v. A função deve fazer a
busca de maneira sequencial e armazenar os índices em que a chave se encontra e preencher o resto do
vetor com -1. Os vetores v e indices devem ter a mesma capacidade. Protótipo da função*/

#include <stdio.h>

void sequentialSearch(int v[], int n, int key, int indices[]) {
    int i, count = 0;

    for (i = 0; i < n; i++) {
        if (v[i] == key) {
            indices[count++] = i;
        }
    }

    for (; count < n; count++) {
        indices[count] = -1;
    }
}

int main() {
    int v[] = {1, 2, 3, 4, 2, 6, 2, 8, 9, 2};
    int n = sizeof(v) / sizeof(v[0]);
    int key = 2;
    int indices[n];

    sequentialSearch(v, n, key, indices);

    printf("Índices onde a chave %d foi encontrada:\n", key);
    for (int i = 0; i < n; i++) {
        printf("%d ", indices[i]);
    }
    printf("\n");

    return 0;
}
