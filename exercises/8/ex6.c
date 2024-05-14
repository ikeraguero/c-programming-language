/*Escreva uma função que inverte a ordem dos caracteres de uma string*/

#include <stdio.h>
#include <string.h>

void inverter_string(char *str) {
    int tamanho = strlen(str);
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio < fim) {
        char temp = str[inicio];
        str[inicio] = str[fim];
        str[fim] = temp;

        inicio++;
        fim--;
    }
}

int main() {
    char str[100];

    printf("Digite uma string: ");
    scanf("%s", str);

    inverter_string(str);

    printf("A string invertida é: %s\n", str);

    return 0;
}
