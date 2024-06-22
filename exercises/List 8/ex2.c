/*Modifique o código da questão anterior fazendo com que o programa determine quantas vezes o caractere
ocorre na string*/
#include <stdio.h>

int contar_ocorrencias(const char *s, char c) {
    int ocorrencias = 0;
    while (*s != '\0') {
        if (*s == c) {
            ocorrencias++;
        }
        s++;
    }
    return ocorrencias;
}

int main() {
    char s[100];
    char c;
    
    printf("Digite a string: ");
    scanf("%s", s);

    printf("Digite o caractere a ser verificado: ");
    scanf(" %c", &c);

    int num_ocorrencias = contar_ocorrencias(s, c);

    printf("O caractere '%c' ocorre %d vezes na string.\n", c, num_ocorrencias);

    return 0;
}
