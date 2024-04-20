/*2 - Dado um vetor de reais, faça a ordenação em ordem crescente ou decrescente.
O usuário poderá indicar a quantidade de elementos do vetor (que deve ser maior que zero). Os
elementos do vetor devem ser preenchidos com valores randômicos. Os valores do vetor devem ser
mostrados na tela usando uma função com VLA. Após isto, o usuário poderá indicar se quer a
ordenação dos valores do vetor em ordem crescente ou decrescente. Use uma única função (também
com VLA) para fazer a ordenação dos valores do vetor. Para isso, sugere-se o uso de um parâmetro
adicional indicando a ordem (‘c’=crescente e ‘d’=decrescente). Ao final, mostre os valores do vetor
após a ordenação. Sugestões de protótipos para as funções:*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_array_random(int size, float array[size]) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = (float)rand() / RAND_MAX;
    }
}

void show_array(int size, float array[size]) {
    printf("Array antes da ordenação: ");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

void sort_array(int size, float array[size], char order) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((order == 'c' && array[i] > array[j]) || (order == 'd' && array[i] < array[j])) {
                float temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main() {
    int size;
    printf("Digite o tamanho do array: ");
    scanf("%d", &size);
    
    if (size <= 0) {
        printf("O tamanho do array deve ser maior que zero.\n");
        return 1;
    }

    float array[size];

    fill_array_random(size, array);
    show_array(size, array);

    char order;
    printf("Digite 'c' para ordem crescente ou 'd' para ordem decrescente: ");
    scanf(" %c", &order);

    if (order != 'c' && order != 'd') {
        printf("Ordem inválida. Saindo...\n");
        return 1;
    }

    sort_array(size, array, order);

    printf("Array após a ordenação: ");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");

    return 0;
}
