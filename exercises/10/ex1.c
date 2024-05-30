/* Escreva uma função que recebe um vetor float v e sua capacidade n, e retorne o endereço de um
vetor alocado dinamicamente, cujo conteúdo seja o mesmo de v, ou seja, a função retorna um
clone do vetor v. Faça o programa principal com a entrada de dados (ou um vetor fixo), chame a
função e mostre o vetor resultante na tela. Protótipo da função:
float *clone( float *v, int n );*/

#include <stdio.h>
#include <stdlib.h>

float *clone(float *v, int n) {
    float *clone_v = (float *)malloc(n * sizeof(float));
    
    if (clone_v == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1); 
    }
    
    for (int i = 0; i < n; i++) {
        clone_v[i] = v[i];
    }
    
    return clone_v;
}

int main() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    
    float *v = (float *)malloc(n * sizeof(float));
    
    if (v == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1; 
    }
    
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &v[i]);
    }
    
    float *clone_v = clone(v, n);
    
    printf("Vetor clone:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", clone_v[i]);
    }
    printf("\n");
    
    free(v);
    free(clone_v);
    
    return 0;
}
