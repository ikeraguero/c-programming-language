/*Implemente a série de Taylor para calcular a função exponencial ex:
O algoritmo deve solicitar como entrada o valor de x e quantidade de termos da série.*/

/*Implemente o programa para determinar o valor da constante e. O programa deve solicitar como
entrada a quantidade n de termos da série.*/

#include <stdio.h>

double fat(int k) {
    if (k==0 || k==1) {
        return 1;
    } else {
        return k * fat(k-1);
    }
}

double taylor_series(double x, int n, int i) {
    if (i == n) {
        return pow(x, i) / fat(i);
    }
    return (pow(x, i) / fat(i)) + taylor_series(x, n, i + 1);
}

int main() {
    int x, n;
    printf("Informe x e n: ");
    scanf("%i %i", &x, &n);
    double result = 1 + taylor_series(x, n, 1);
    printf("%f", result);
}                                                 