/*Faça um programa que mostre na tela os n termos da sequência de Fibonacci modificada,
considerando que os dois primeiros termos são: 2 e 2, respectivamente. Por exemplo, dado n = 5,
temos: 2, 2, 4, 6 e 10. A determinação do n-ésimo termo da sequência deve ser feita por uma
função recursiva que tem o seguinte protótipo: int fibo(int n);*/

#include <stdio.h>

int fibo(int n) {
    if (n==1 || n ==2) {
        return 2;
    } else {
        return fibo(n-1) + fibo(n-2);
    }
}

int main() {
    int n;
    printf("Informe um valor n: ");
    scanf("%i", &n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", fibo(i));
    }
}