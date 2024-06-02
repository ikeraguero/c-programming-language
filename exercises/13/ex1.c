/*) Faça um programa que aloque uma matriz quadrada dinamicamente, usando um ponteiro para ponteiro
(int**). O tamanho (ordem) da matriz deve ser informado pelo usuário. Após a entrada de dados, o
programa deve armazenar os valores da diagonal secundária em um vetor V (também alocado
dinamicamente), que por fim deve ser mostrado na tela. A geração do vetor V deve ser feita através da
função a seguir:
int *diagonal_secundaria( int **matriz, int ordem )*/

int main() {
    int ordem;
    printf("Informe a ordem da matriz: ");
    scanf("%d", &ordem);
    
    int **matriz = (int **)malloc(ordem * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro ao alocar memória para a matriz.\n");
        exit(1);
    }
    for (int i = 0; i < ordem; i++) {
        matriz[i] = (int *)malloc(ordem * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória para a matriz.\n");
            exit(1);
        }
    }
    
    printf("Digite os valores da matriz:\n");
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            printf("matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    int *vetor = diagonal_secundaria(matriz, ordem);
    
    printf("Diagonal secundária:\n");
    for (int i = 0; i < ordem; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    free(vetor);
    for (int i = 0; i < ordem; i++) {
        free(matriz[i]);
    }
    free(matriz);
    
    return 0;
}