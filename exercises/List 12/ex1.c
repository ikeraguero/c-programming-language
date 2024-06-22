/*Crie um programa que crie um vetor de ponteiros do tipo float com 5 elementos que irão
armazenar as notas de 5 estudantes. Em seguida, pergunte ao usuário qual o número de notas.
Após isto, aloque dinamicamente os 5 ponteiros do vetor criado de modo que possam armazenar
a quantidade de notas indicada (que será igual para todos os estudantes). Por fim, peça para o
usuário digitar todas as notas de todos os estudantes e mostre-as na tela.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    float *notas[5]; 
    int num_notas;
    
    printf("Digite o número de notas para cada estudante: ");
    scanf("%d", &num_notas);
    
    for (int i = 0; i < 5; i++) {
        notas[i] = (float *)malloc(num_notas * sizeof(float));
        if (notas[i] == NULL) {
            printf("Erro ao alocar memória!\n");
            return 1; 
        }
    }
    
    for (int i = 0; i < 5; i++) {
        printf("Digite as notas do estudante %d:\n", i + 1);
        for (int j = 0; j < num_notas; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }
    
    printf("\nNotas dos estudantes:\n");
    for (int i = 0; i < 5; i++) {
        printf("Estudante %d: ", i + 1);
        for (int j = 0; j < num_notas; j++) {
            printf("%.2f ", notas[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < 5; i++) {
        free(notas[i]);
    }
    
    return 0;
}
