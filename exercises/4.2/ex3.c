/*Faça um programa que calcule o somatório dos k termos da série harmônica e, ao final, mostre o
somatório dos termos. O número de termos da série (k) é definido pelo usuário*/

#include <stdio.h>

float somatory(int n) {
    if (n==1) {
        return 1;
    }
    return 1.0 /n + somatory(n-1);
}

int main() {
    int n;
    printf("Informe o número de termos: ");
    scanf("%i", &n);
    float result = somatory(n);
    printf("O somatório dos %d termos da série harmônica é: %f\n", n, result);
}