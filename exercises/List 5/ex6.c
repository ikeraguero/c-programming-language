/*6 – Escreva um programa para a geração da seguinte matriz que deverá ser impressa na tela:
1 1 1 1 1 1
1 2 2 2 2 1
1 2 3 3 2 1
1 2 3 3 2 1
1 2 2 2 2 1
1 1 1 1 1 1
Dica: preencha em 3 etapas, primeiro só os valores 1, depois só os valores 2 e por último, os valores 3*/

#include <stdio.h>

int main() {
    int size = 6;
    int matrix[size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 1;
        }
    }

    for (int i = 1; i < size - 1; i++) {
        for (int j = 1; j < size - 1; j++) {
            matrix[i][j] = 2;
        }
    }

    for (int i = 2; i < size - 2; i++) {
        for (int j = 2; j < size - 2; j++) {
            matrix[i][j] = 3;
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
