/*Faça um programa que leia um inteiro n e determine a soma S da seguinte forma: 1 + 2 + 3 + 4 + ...
+ n. Escreva duas versões de funções: iterativa e recursiva*/

#include <stdio.h>

int iterative_sum(int n) {
    int sum = 0;
    for (int i=1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int recursive_sum(int n) {
    if (n!=0) {
        return n + recursive_sum(n-1);
    } else if (n==0) {
        return 0;
    }
}

int main() {
    int n, recursive, iterative;
    printf("Informe n: ");
    scanf("%i", &n);
    recursive = recursive_sum(n);
    iterative = iterative_sum(n);

    printf("Resultado da função iterativa: %i \n", iterative);
    printf("Resultado da função recursiva: %i \n",recursive);
}