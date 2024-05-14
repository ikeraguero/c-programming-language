/*Escreva um programa que converta uma string que contém somente dígitos em um valor inteiro (variável
int).*/

#include <stdio.h>

int converter_para_inteiro(char *string) {
    int valor = 0;
    while (*string) {
        valor = valor * 10 + (*string - '0');
        string++; 
    }
    return valor;
}

int main() {
    char string[100]; 
    printf("Digite uma string contendo somente dígitos: ");
    scanf("%s", string);
    
    int valor_inteiro = converter_para_inteiro(string);

    printf("O valor inteiro convertido é: %d\n", valor_inteiro);

    return 0;
}
