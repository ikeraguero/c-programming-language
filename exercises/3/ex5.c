/*Faça um programa que, dados k e n, mostre na tela os n primeiros números primos acima de k. A
verificação do número (se é ou não é primo) deve ser feita através de uma função.*/

#include <stdio.h>

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    
    for (int i = 2; i * i <= n; i++) {
        if (n%i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int k, n, count =0;
    printf("Informe k e n: ");
    scanf("%i %i", &k, &n);

    for (int i=k; count < n; i++) {
        if(is_prime(i)) {
            printf("%i \n", i);
            count++;
        }
    }
}