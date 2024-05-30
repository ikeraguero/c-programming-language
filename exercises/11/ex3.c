/*Escreva uma função que realiza a união entre dois conjuntos de inteiros contidos nos vetores v1
e v2. A função recebe os vetores e suas respectivas capacidades (n1 e n2) como parâmetros de
entrada e retorna o endereço do vetor alocado (contendo a união entre v1 e v2). Além disso, há
um parâmetro passado por referência (ponteiro p3), que serve para “retornar” a capacidade do
vetor gerado. Faça o programa principal invocando a função (a estrutura do programa é
semelhante ao exemplo dado em aula – intersecção). Protótipo da função:
int *uniao( int *v1, int n1, int *v2, int n2, int *p3 );*/

#include <stdio.h>
#include <stdlib.h>

int *uniao(int *v1, int n1, int *v2, int n2, int *p3) {
    // Aloca memória para o vetor de união
    int *uniao_v = (int *)malloc((n1 + n2) * sizeof(int));
    if (uniao_v == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1); // Termina o programa com erro
    }
    
    // Copia os elementos do vetor v1 para o vetor de união
    for (int i = 0; i < n1; i++) {
        uniao_v[i] = v1[i];
    }
    
    // Copia os elementos do vetor v2 para o vetor de união
    for (int i = 0; i < n2; i++) {
        uniao_v[n1 + i] = v2[i];
    }
    
    // Atualiza a capacidade do vetor gerado
    *p3 = n1 + n2;
    
    return uniao_v;
}

int main() {
    int v1[] = {1, 3, 5, 7}; // Primeiro vetor
    int n1 = sizeof(v1) / sizeof(v1[0]); // Capacidade do primeiro vetor
    
    int v2[] = {2, 4, 6, 8}; // Segundo vetor
    int n2 = sizeof(v2) / sizeof(v2[0]); // Capacidade do segundo vetor
    
    int capacidade_uniao; // Capacidade do vetor de união
    
    // Chama a função de união
    int *uniao_v = uniao(v1, n1, v2, n2, &capacidade_uniao);
    
    // Imprime o vetor de união
    printf("Vetor de união:\n");
    for (int i = 0; i < capacidade_uniao; i++) {
        printf("%d ", uniao_v[i]);
    }
    printf("\n");
    
    // Libera a memória alocada para o vetor de união
    free(uniao_v);
    
    return 0;
}
