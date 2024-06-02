/*Escreva um programa que realize a multiplicação entre duas matrizes A e B alocadas dinamicamente. A
matriz resultante também deve ser gerada dinamicamente, de acordo com o algoritmo de multiplicação.*/

#include <stdio.h>
#include <stdlib.h>

int** alocar_matriz(int linhas, int colunas) {
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro ao alocar memória para a matriz.\n");
        exit(1);
    }
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória para a matriz.\n");
            exit(1);
        }
    }
    return matriz;
}

void liberar_matriz(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void ler_matriz(int **matriz, int linhas, int colunas, char nome) {
    printf("Digite os valores da matriz %c:\n", nome);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%c[%d][%d]: ", nome, i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

int main() {
    int linhasA, colunasA, linhasB, colunasB;

    printf("Informe o número de linhas da matriz A: ");
    scanf("%d", &linhasA);
    printf("Informe o número de colunas da matriz A: ");
    scanf("%d", &colunasA);

    printf("Informe o número de linhas da matriz B: ");
    scanf("%d", &linhasB);
    printf("Informe o número de colunas da matriz B: ");
    scanf("%d", &colunasB);

    if (colunasA != linhasB) {
        printf("Multiplicação não é possível. O número de colunas de A deve ser igual ao número de linhas de B.\n");
        return 1;
    }

    int **A = alocar_matriz(linhasA, colunasA);
    int **B = alocar_matriz(linhasB, colunasB);
    int **C = alocar_matriz(linhasA, colunasB);

    ler_matriz(A, linhasA, colunasA, 'A');
    ler_matriz(B, linhasB, colunasB, 'B');

    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            C[i][j] = 0;
        }
    }

    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            for (int k = 0; k < colunasA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("Matriz resultante C (A x B):\n");
    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    liberar_matriz(A, linhasA);
    liberar_matriz(B, linhasB);
    liberar_matriz(C, linhasA);

    return 0;
}
