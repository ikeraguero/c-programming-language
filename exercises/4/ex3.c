/*Faça um programa que leia um inteiro n e utilize uma função (faça as versões iterativa e
recursiva) para determinar a soma S da série harmônica definida a seguir:*/

#include <stdio.h>

float harmonic_series_recursive(int n) {
    if (n!=0) {
        return 1.0/n + harmonic_series_recursive(n-1);
    }
    else if (n==0) {
        return 0.0;
    }
}

float harmonic_series_iterative(int n) {
    float sum = 0.0;
    for(int i=1; i<=n; i++) {
        sum += 1.0/i;
    }
    return sum;
}

int main() {
    int n;
    float sum;
    printf("Informe n: ");
    scanf("%i", &n);
    float iterative = harmonic_series_iterative(n);
    float recursive = harmonic_series_recursive(n);
    printf("Resultado da função iterativa: %.2f \n", iterative);
    printf("Resultado da função recursiva: %.2f \n", recursive);
}