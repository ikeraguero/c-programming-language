/*Faça um programa que determine o menor valor de uma matriz 3x4, bem como suas coordenadas (linha
e coluna). Tal processamento deve ser feito por uma função que recebe a matriz e “retorna” o menor
elemento e suas coordenadas (i e j).
void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ);*/

#include <stdio.h>

void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ) {
    *pMin = mat[0][0];
    *pI = 0;
    *pJ = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (mat[i][j] < *pMin) {
                *pMin = mat[i][j];
                *pI = i;
                *pJ = j;
            }
        }
    }
}

int main() {
    float mat[3][4];

    printf("Informe os elementos da matriz 3x4:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%f", &mat[i][j]);
        }
    }

    float min;
    int linha, coluna;
    min_matriz(mat, &min, &linha, &coluna);

    printf("O menor valor da matriz é %.2f e está na linha %d, coluna %d.\n", min, linha, coluna);

    return 0;
}
