/* Implemente um programa para calcular o valor aproximado de π, conforme a série de Gregory-
Leibniz. O número de termos é definido pelo usuário.*/

#include <stdio.h>

double gregory_leibniz_series(int n) {
    double pi_approx = 0;
    for (int k = 0; k < n; k++) {
        pi_approx += (k % 2 == 0 ? 1.0 : -1.0) / (2 * k + 1);
    }
    return pi_approx * 4; 
}

int main() {
    int n;
    printf("Digite o número de termos (n): ");
    scanf("%d", &n);
    double pi_approximation = gregory_leibniz_series(n);
    printf("Aproximação de π com %d termos da série de Gregory-Leibniz: %lf\n", n, pi_approximation);
    return 0;
}
