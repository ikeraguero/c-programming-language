/*Faça um programa que Leia N valores inteiros (N é informado pelo usuário) e em seguida leia uma
sequência de N valores inteiros. O programa deve alocar uma estrutura usando um ponteiro p (int **p),
e deve armazenar os valores digitados e seus divisores conforme a figura a seguir. Repare que as
alocações devem respeitar as quantidades de valores armazenados (é preciso calcular a quantidade de
divisores de cada número para saber o espaço necessário). Ao final, percorra a estrutura e mostre cada
valor e seus respectivos divisores, a faça a liberação da memória.*/

#include <stdio.h>
#include <stdlib.h>

int* encontrar_divisores(int num, int* quantidade) {
    int* divisores = NULL;
    *quantidade = 0;

    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            divisores = (int*)realloc(divisores, (*quantidade + 1) * sizeof(int));
            if (divisores == NULL) {
                printf("Erro ao alocar memória para os divisores.\n");
                exit(1);
            }
            divisores[*quantidade] = i;
            (*quantidade)++;
        }
    }
    return divisores;
}

int main() {
    int N;

    printf("Informe a quantidade de valores (N): ");
    scanf("%d", &N);

    int** p = (int**)malloc(N * sizeof(int*));
    if (p == NULL) {
        printf("Erro ao alocar memória para a estrutura.\n");
        exit(1);
    }

    int* quantidades = (int*)malloc(N * sizeof(int));
    if (quantidades == NULL) {
        printf("Erro ao alocar memória para as quantidades.\n");
        exit(1);
    }

    for (int i = 0; i < N; i++) {
        int valor;
        printf("Informe o valor %d: ", i + 1);
        scanf("%d", &valor);

        p[i] = encontrar_divisores(valor, &quantidades[i]);
    }

    for (int i = 0; i < N; i++) {
        printf("Valor %d tem %d divisores: ", i + 1, quantidades[i]);
        for (int j = 0; j < quantidades[i]; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        free(p[i]);
    }
    free(p);
    free(quantidades);

    return 0;
}
