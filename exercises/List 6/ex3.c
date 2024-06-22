/*Faça uma função que recebe um vetor e sua capacidade como parâmetros e retorna o somatório dos
números primos contidos no vetor. Recomenda-se utilizar a função de verificação (se um número é primo
ou não) já implemetada. Protótipo:*/

#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int sumPrimes(int array[], int capacity) {
    int sum = 0;
    for (int i = 0; i < capacity; i++) {
        if (isPrime(array[i])) {
            sum += array[i];
        }
    }
    return sum;
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int capacity = sizeof(array) / sizeof(array[0]);

    int result = sumPrimes(array, capacity);
    printf("A soma dos números primos no vetor é: %d\n", result);

    return 0;
}
