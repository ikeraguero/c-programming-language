/*1) Dados uma string s e um caractere c faça um programa que verifique se s contém c. Dica: a implementação
dentro de uma função facilita a definição da solução.*/

#include <stdio.h>

int contem_caractere(const char *s, char c) {
    while (*s != '\0') {
        if (*s == c) {
            return 1;
        }
        s++;
    }
    return 0;
}

int main() {
    char s[100];
    char c;
    
    printf("Digite a string: ");
    scanf("%s", s);

    printf("Digite o caractere a ser verificado: ");
    scanf(" %c", &c);

    if (contem_caractere(s, c)) {
        printf("A string contém o caractere '%c'.\n", c);
    } else {
        printf("A string não contém o caractere '%c'.\n", c);
    }

    return 0;
}
