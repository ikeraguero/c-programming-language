#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char palavra[100]; 
    int i, j, palindromo = 1; 

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    for (i = 0; palavra[i] != '\0'; i++) {
        palavra[i] = tolower(palavra[i]);
    }

    for (i = 0, j = strlen(palavra) - 1; i < j; i++, j--) {
        if (palavra[i] != palavra[j]) {
            palindromo = 0; 
            break;
        }
    }

    if (palindromo) {
        printf("A palavra '%s' é um palíndromo.\n", palavra);
    } else {
        printf("A palavra '%s' não é um palíndromo.\n", palavra);
    }

    return 0;
}
