/* Escreva uma função que recebe como parâmetros uma string s e um inteiro n, e retorna nova
string nova contendo s repetida n vezes. Por exemplo, s = “Abc” e n = 4 tem como resultado a
string “AbcAbcAbcAbc”. Faça o programa principal chamando a função. Protótipo da função:
char *repetidor( char *s, int n );*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *repetidor(char *s, int n) {
    int tamanho_s = strlen(s);
    int tamanho_nova_string = tamanho_s * n;

    char *nova_string = (char *)malloc((tamanho_nova_string + 1) * sizeof(char));
    
    if (nova_string == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1); 
    }
    
    for (int i = 0; i < n; i++) {
        strcat(nova_string, s);
    }
    
    return nova_string;
}

int main() {
    char s[100];
    int n;
    
    printf("Digite a string: ");
    scanf("%s", s);
    printf("Digite o número de repetições: ");
    scanf("%d", &n);
    
    char *nova_string = repetidor(s, n);
    
    printf("Nova string: %s\n", nova_string);
    
    free(nova_string);
    
    return 0;
}
