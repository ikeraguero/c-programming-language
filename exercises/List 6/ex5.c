/*Implemente a versão recursiva da função que faz a busca sequencial em um vetor. Protótipo da função:*/

#include <stdio.h>

int sequential_search_recursive(int v[], int n, int key) {
    if (n <= 0) {
        return -1; 
    if (v[n - 1] == key) {
        return n - 1; 
    }
    return sequential_search_recursive(v, n - 1, key); 
}
}
int main() {
    int v[] = {1, 2, 3, 4, 2, 6, 2, 8, 9, 2};
    int n = sizeof(v) / sizeof(v[0]);
    int key = 2;

    int index = sequential_search_recursive(v, n, key);

    if (index != -1) {
        printf("A chave %d foi encontrada no índice %d.\n", key, index);
    } else {
        printf("A chave %d não foi encontrada no vetor.\n", key);
    }

    return 0;
}
