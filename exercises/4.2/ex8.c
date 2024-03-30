/*Escreva um algoritmo que determine o valor aproximado do cosseno de x com base na série abaixo.
O número de termos da série bem como o valor de x são determinados pelo usuário. Nesta série, o
primeiro é denominado termo 0 (termo zero)*/

#include <stdio.h>
#include <math.h>

double calculate_cos(double x, int n) {
    double cosine = 1; // The first term is always 1
    int sign = -1; // Start with negative sign for the second term
    int exponent = 2; // The second term is x^2
    for (int i = 1; i <= n; i++) {
        double term = sign * pow(x, exponent) / tgamma(exponent + 1);
        cosine += term;
        sign *= -1; // Alternate the sign
        exponent += 2; // Increment the exponent for the next even term
    }
    return cosine;
}

int main() {
    double x;
    int n;
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    printf("Enter the number of terms (n): ");
    scanf("%d", &n);
    double approx_cosine = calculate_cos(x, n);
    printf("Approximate value of cos(%.2lf) with %d terms of the series is: %.15lf\n", x, n, approx_cosine);
    return 0;
}