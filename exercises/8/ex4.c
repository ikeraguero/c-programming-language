/*4) Faça um programa que verifica se uma string contém somente dígitos decimais (0 a 9)*/

#include <stdio.h>
#include <ctype.h>

int contem_apenas_digitos(char *string) {
    while (*string) {
        if (!isdigit(*string)) {
            return 0; 
        }
        string++; 
    }
    return 1;
}

int main() {
    char string[100]; 

    printf("Digite uma string: ");
    scanf("%s", string);

    if (contem_apenas_digitos(string)) {
        printf("A string contém apenas dígitos decimais.\n");
    } else {
        printf("A string NÃO contém apenas dígitos decimais.\n");
    }

    return 0;
}
