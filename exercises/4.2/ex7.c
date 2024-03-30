/*Escreva um algoritmo que determine o valor aproximado do seno de x com base na série abaixo. O
número de termos da série bem como o valor de x são determinados pelo usuário. Nesta série, o
primeiro é denominado termo 0 (termo zero)*/

#include <stdio.h>
#include <math.h>

double calculate_sine(double x, int n) {
    double sine = 0;
    int sign = 1;
    int exponent = 1;
    for (int i = 0; i < n; i++) {
        double term = sign * pow(x, exponent) / tgamma(exponent + 1);
        sine += term;
        sign *= -1;
        exponent += 2;
    }
    return sine;
}

int main() {
    double x;
    int n;
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    printf("Enter the number of terms (n): ");
    scanf("%d", &n);
    double approx_sine = calculate_sine(x, n);
    printf("Approximate value of sin(%.2lf) with %d terms of the series is: %.15lf\n", x, n, approx_sine);
    return 0;
}
