/*Faça um programa que leia uma certa quantidade de inteiros que são armazenados num vetor v.
A quantidade NÃO será indicada previamente pelo usuário e o programa deve alocar/realocar
espaço para v, sempre que necessário. À medida que os valores são digitados e armazenador no
vetor v, o programa também deve armazenar os valores positivos em um vetor vp e o valores
negativos no vetor vn. Da mesma forma como ocorre com o vetor v, os dois outros vetores (vp e
vn) devem ser alocados dinamicamente. Os vetores vp e vn não devem conter zeros. A cada
digitação de um novo valor, o programa deve perguntar se o usuário deseja digitar outro número.
A digitação encerra quando a resposta do usuário é negativa. Ao final, imprima os três vetores.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *v = NULL; 
    int *vp = NULL; 
    int *vn = NULL;
    
    int tamanho_v = 0; 
    int tamanho_vp = 0;
    int tamanho_vn = 0;
    
    char continuar; 
    
    do {

        printf("Digite um número: ");
        int numero;
        scanf("%d", &numero);
        

        v = (int *)realloc(v, (tamanho_v + 1) * sizeof(int));
        

        if (v == NULL) {
            printf("Erro de alocação de memória!\n");
            exit(1); 
        }
        
        v[tamanho_v] = numero;
        tamanho_v++;

        if (numero > 0) {
            vp = (int *)realloc(vp, (tamanho_vp + 1) * sizeof(int));
            if (vp == NULL) {
                printf("Erro de alocação de memória!\n");
                exit(1); 
            }
            vp[tamanho_vp] = numero;
            tamanho_vp++;
        } else if (numero < 0) {
            vn = (int *)realloc(vn, (tamanho_vn + 1) * sizeof(int));
            if (vn == NULL) {
                printf("Erro de alocação de memória!\n");
                exit(1); 
            }
            vn[tamanho_vn] = numero;
            tamanho_vn++;
        }
        

        printf("Deseja digitar outro número? (S/N): ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');
    

    printf("Vetor v:\n");
    for (int i = 0; i < tamanho_v; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    
    printf("Vetor vp:\n");
    for (int i = 0; i < tamanho_vp; i++) {
        printf("%d ", vp[i]);
    }
    printf("\n");
    
    printf("Vetor vn:\n");
    for (int i = 0; i < tamanho_vn; i++) {
        printf("%d ", vn[i]);
    }
    printf("\n");
    
    free(v);
    free(vp);
    free(vn);
    
    return 0;
}
