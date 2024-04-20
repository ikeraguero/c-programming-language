/*5 – Dadas 2 matrizes A e B compatíveis, gerar a matriz C, produto de AxB.
O programa deve ler as dimensões (número de linhas e número de colunas) tanto da matriz A quanto
da matriz B. Se ambas as dimensões forem compatíveis para uma operação de multiplicação (número
de colunas de A deve ser igual ao número de linhas de B), o programa deve prosseguir. Caso
contrário, deve mostrar uma mensagem de erro para o usuário e encerrar a execução. Os valores das
matrizes A e B devem ser gerados randomicamente para as duas matrizes(A e B). Deve-se usar uma
mesma função para geração dos valores randômicos usando VLA. Após isso, mostrar os valores de
ambas as matrizes (uma de cada vez) na tela. Também sugere-se usar uma única função com VLA. Em
seguida, gerar a matriz C com o produto da matriz A pela matriz B. A matriz produto também deverá
ser impressa na tela com a mesma função usada para imprimir as duas primeiras matrizes. Sugestões
para os protótipos das funções:
void preenche_matriz_rand(int lin,int col,int mat[lin][col]);
void mostra_matriz(int lin,int col,int mat[lin][col]);
void produto_matrizes(int l1,int c1,int l2,int c2,int A[l1][c1],int B[l2][c2],int C[l1][c2])*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_matrix_random(int rows, int cols, int matrix[rows][cols]) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;  // Random integer between 0 and 99
        }
    }
}

void show_matrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrix_product(int rows_A, int cols_A, int rows_B, int cols_B, int matrix_A[rows_A][cols_A], int matrix_B[rows_B][cols_B], int matrix_C[rows_A][cols_B]) {
    if (cols_A != rows_B) {
        printf("Erro: As dimensões das matrizes não são compatíveis para multiplicação.\n");
        exit(1);
    }

    for (int i = 0; i < rows_A; i++) {
        for (int j = 0; j < cols_B; j++) {
            matrix_C[i][j] = 0;
            for (int k = 0; k < cols_A; k++) {
                matrix_C[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }
}

int main() {
    int rows_A, cols_A, rows_B, cols_B;

    printf("Digite o número de linhas da matriz A: ");
    scanf("%d", &rows_A);
    printf("Digite o número de colunas da matriz A: ");
    scanf("%d", &cols_A);

    printf("Digite o número de linhas da matriz B: ");
    scanf("%d", &rows_B);
    printf("Digite o número de colunas da matriz B: ");
    scanf("%d", &cols_B);

    if (cols_A != rows_B) {
        printf("Erro: As dimensões das matrizes não são compatíveis para multiplicação.\n");
        return 1;
    }

    int matrix_A[rows_A][cols_A], matrix_B[rows_B][cols_B], matrix_C[rows_A][cols_B];

    fill_matrix_random(rows_A, cols_A, matrix_A);
    fill_matrix_random(rows_B, cols_B, matrix_B);

    printf("Matriz A:\n");
    show_matrix(rows_A, cols_A, matrix_A);

    printf("\nMatriz B:\n");
    show_matrix(rows_B, cols_B, matrix_B);

    matrix_product(rows_A, cols_A, rows_B, cols_B, matrix_A, matrix_B, matrix_C);

    printf("\nMatriz Produto (A x B):\n");
    show_matrix(rows_A, cols_B, matrix_C);

    return 0;
}
