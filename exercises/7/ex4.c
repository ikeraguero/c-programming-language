/*4 - Dada uma matriz original qualquer, gere a matriz transposta desta original.
A dimensão da matriz original (número de linhas e número de colunas) deve ser indicada pelo
usuário. Ambos devem maiores que 1. Os valores da matriz original podem ser gerados
randomicamente numa função. A matriz transposta deve ser uma outra matriz (não sobrescrever os
valores da matriz original) e pode ser gerada em uma função. Os valores de ambas as matrizes devem
ser mostrados na tela. Recomenda-se usar uma mesma função com VLA. Sugestões para os
protótipos das funções:
void preenche_matriz_rand(int lin,int col,int mat[lin][col]);
void mostra_matriz(int lin,int col,int mat[lin][col]);
void gera_matriz_transposta(int lin,int col,int mat[lin][col],int transp[col][lin]);*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preenche_matriz_aleatoria(int linhas, int colunas, int matriz[linhas][colunas]) {
    srand(time(NULL));
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = rand() % 100;  // Número inteiro aleatório entre 0 e 99
        }
    }
}

void mostra_matriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    printf("Matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void gera_matriz_transposta(int linhas, int colunas, int matriz[linhas][colunas], int transposta[colunas][linhas]) {
    for (int i = 0; i < colunas; i++) {
        for (int j = 0; j < linhas; j++) {
            transposta[i][j] = matriz[j][i];
        }
    }
}

int main() {
    int linhas, colunas;
    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);
    
    if (linhas <= 1 || colunas <= 1) {
        printf("Tanto o número de linhas quanto o número de colunas devem ser maiores que 1.\n");
        return 1;  // Retorna erro
    }

    int matriz[linhas][colunas];
    preenche_matriz_aleatoria(linhas, colunas, matriz);
    printf("Matriz Original:\n");
    mostra_matriz(linhas, colunas, matriz);

    int transposta[colunas][linhas];
    gera_matriz_transposta(linhas, colunas, matriz, transposta);
    printf("\nMatriz Transposta:\n");
    mostra_matriz(colunas, linhas, transposta);

    return 0;
}
