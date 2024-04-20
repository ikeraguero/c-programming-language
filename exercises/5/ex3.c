/*3 – Escreva um programa que:
• leia um conjunto A de 20 valores numéricos e armazene-os em um vetor;
• calcule e imprima o valor de S, onde: s= (a1-a20)² + (a2-a19)²...*/

#include <stdio.h>
#include <math.h>

int main() {
    double a[20], s =0;
    int count = 21;
    for (int i=0; i<20; i++) {
        printf("Informe um valor: ");
        scanf("%lf", &a[i]);
    }
    for (int i=0; i<20; i++) {
        s += pow(2, (a[i+1] - a[count-1]));
    }
}