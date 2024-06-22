/*2) Faça uma função que recebe três valores inteiros e retorna o maior valor. É preciso considerar que
pode haver dois (ou mesmo os três) parâmetros iguais como sendo o maior valor. Por exemplo, os
parâmetros poderiam ser 5, 8 e 8. Neste caso, a função deve retornar 8.*/

#include <stdio.h>

int greater_value(int n1, int n2, int n3) {
    if (n1 >= n2 && n1 >= n3) {
        printf("%i é o maior valor", n1);
        return n1;
    }
    else if (n2>=n1 && n2>=n3) {
        printf("%i é o maior valor", n2);
        return n2;
    }
    else if(n3>=n2 && n3>=n1) {
        printf("%i é o maior valor", n3);
        return n3;
    }
    return 0;
}

int main() {
    int n1, n2, n3;
    printf("Informe 3 valores inteiros:");
    scanf("%i %i %i", &n1, &n2, &n3);
    greater_value(n1, n2, n3);
}