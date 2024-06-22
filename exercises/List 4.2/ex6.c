/*Implemente um programa para calcular o valor aproximado de π, conforme a série de Nilakantha.
O número de termos é definido pelo usuário.
Série de Nilakantha*/

#include <stdio.h>

double nilakantha_series(int n) {
    double pi_approx = 3.0; // Começamos com 3, o primeiro termo da série
    int divisor = 2;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            pi_approx += 4.0 / (divisor * (divisor + 1) * (divisor + 2));
        } else {
            pi_approx -= 4.0 / (divisor * (divisor + 1) * (divisor + 2));
        }
        divisor += 2;
    }
    return pi_approx;
}

int main() {
    int n;
    printf("Digite o número de termos (n): ");
    scanf("%d", &n);
    double pi_approximation = nilakantha_series(n);
    printf("Aproximação de π com %d termos da série de Nilakantha: %lf\n", n, pi_approximation);
    return 0;
}
