/*Faça um programa que leia um inteiro n e utilize uma função (faça as versões iterativa e
recursiva) para calcular o somatório que determina o valor da constante e:*/

#include <stdio.h>

int fat(int k) {
    if(k== 0 || k==1) {
        return 1;
    } else {
    return k * fat(k-1);
    };
};

float sum_recursive(int n) {
    if (n!=0) {
        return (1.0/fat(n)) + (sum_recursive(n-1));
    } else if (n==0) {
        return 1;
    }
}   

float sum_iterative(int n) {
    float sum = 0;
    for (int i=0; i <= n; i++) {
        sum += 1.0/fat(i);
    }
    return sum;
}

int main() {
    int n;
    printf("Informe n: ");
    scanf("%i", &n);
    float iterative = sum_iterative(n);
    float recursive = sum_recursive(n);
    printf("Resultado da função iterativa: %.2f \n", iterative);
    printf("Resultado da função recursiva: %.2f \n", recursive);
}