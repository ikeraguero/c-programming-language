/*
2 – Escreva um programa que leia um vetor A de 10 elementos reais. Após isso,
construa e imprima um outro vetor B formado da seguinte maneira:
- os elementos de índice par são os correspondentes de A divididos por 2;
- os elementos de índice ímpar são os correspondentes de A multiplicados por 3*/

#include <stdio.h>

int main() {
    double a[10];
    double b[10];
    for (int i=0; i < 10; i++) {
        printf("Informe um valor: ");
        scanf("%lf", &a[i]);
    }

    for (int i=0; i<10; i++) {
        if  (i%2==0) {
            b[i] = a[i]/2;
        } else {
            b[i] = a[i]*3;
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", b[i]);
    }
    printf("\n");
}
