/*Faça um programa que calcule o somatório dos k termos da série definida a seguir e, ao final, mostre
o somatório dos termos (o resultado converge para o logaritmo natural de 2). O número de termos
da série (n) é definido pelo usuário.*/

#include <stdio.h>

double serie_gregory_leibniz(int n) {
    double soma = 0;
    for (int k = 0; k < n; k++) {
        if (k % 2 == 0) {
            soma += 1.0 / (2 * k + 1);
        } else {
            soma -= 1.0 / (2 * k + 1);
        }
    }
    return soma;
}

int main() {
    int n;
    printf("Digite o número de termos (n): ");
    scanf("%d", &n);
    double resultado = serie_gregory_leibniz(n);
    printf("Soma dos primeiros %d termos da série de Gregory-Leibniz : %lf\n", n, resultado);
    return 0;
}
