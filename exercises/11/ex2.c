/*Considere um vetor v contendo n valores inteiros. Considere também uma chave de busca k (um
valor inteiro) que se deseja procurar dentro do vetor v. Considere ainda que é possível encontrar
de 0 a n ocorrências da chave k no vetor v.
Crie uma função que retorna um vetor (alocado dinamicamente) com os índices em que a chave
se encontra (que sempre deve terminar com -1). A função deve realocar memória sempre que
encontrar um novo valor no vetor para armazenar o novo índice do valor encontrado.
Sugere-se que o protótipo da função seja como a seguir:
int *busca_seq( int v[], int n, int k );*/

#include <stdio.h>
#include <stdlib.h>

int *busca_seq(int v[], int n, int k) {
    int *indices = NULL; 
    int tamanho_indices = 0; 
    int ocorrencias = 0; 

    for (int i = 0; i < n; i++) {
        if (v[i] == k) {
            indices = (int *)realloc(indices, (tamanho_indices + 1) * sizeof(int));
            if (indices == NULL) {
                printf("Erro de alocação de memória!\n");
                exit(1); 
            }
            indices[tamanho_indices] = i; 
            tamanho_indices++;
            ocorrencias++;
        }
    }
    

    if (ocorrencias == 0) {
        indices = (int *)realloc(indices, sizeof(int));
        if (indices == NULL) {
            printf("Erro de alocação de memória!\n");
            exit(1); 
        }
        indices[0] = -1;
    } else {

        indices = (int *)realloc(indices, (tamanho_indices + 1) * sizeof(int));
        if (indices == NULL) {
            printf("Erro de alocação de memória!\n");
            exit(1); 
        }
        indices[tamanho_indices] = -1; 
    }
    
    return indices;
}

int main() {
    int v[] = {1, 5, 3, 7, 9, 5, 2, 5};
    int n = sizeof(v) / sizeof(v[0]); 
    int k = 5; 
    
    int *indices = busca_seq(v, n, k);
    
    printf("Índices onde a chave %d foi encontrada: ", k);
    for (int i = 0; indices[i] != -1; i++) {
        printf("%d ", indices[i]);
    }
    printf("\n");
    
    free(indices);
    
    return 0;
}
