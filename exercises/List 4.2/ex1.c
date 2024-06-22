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

double calculate_e_recursive(int n, int i) {
    if (i == n) {
        return 1.0 / fat(i);
    }
    return (1.0 / fat(i)) + calculate_e_recursive(n, i + 1);
}
int main() {
    int n;
    printf("Informe n: ");
    scanf("%i", &n);
    double result = calculate_e_recursive(n, 0);
    printf("%d \n", result);
}