/*Dados N e K, mostre na tela os N primos a partir de K*/

#include <stdio.h>
#include <stdbool.h>

bool prime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n, k, count = 0;
    printf("Informe a quantidade de primos: ");
    scanf("%i", &n);
    printf("Informe o ponto inicial: ");
    scanf("%i", &k);

    while (count != n) {
        if (prime(k)) {
            printf("%i, ", k);
            count++;
        }
        k++;
    }
}