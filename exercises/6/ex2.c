/*Escreva uma função que recebe um vetor v e um inteiro n. A função deve gerar o n termos de sequência de
Fibonacci dentro de v. Protótipo da função:*/

#include <stdio.h>

void fibonacci(int v[], int n) {
    int i;
    v[0] = 0;
    v[1] = 1;

    for (i = 2; i < n; i++) {
        v[i] = v[i - 1] + v[i - 2];
    }
}

int main() {
    int n = 10;
    int sequence[n];

    fibonacci(sequence, n);

    printf("Os primeiros %d termos da sequência de Fibonacci são:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");

    return 0;
}
