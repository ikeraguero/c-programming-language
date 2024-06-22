/*Escreva uma função que troca os valores entre duas variáveis do tipo float. Faça um programa que leia
duas variáveis e mostre seus valores na tela. Em seguida, troque os valores (usando a função) e mostre
novamente os valores.
void troca_valor(float *x, float *y);*/

#include <stdio.h>

void troca_valor(float *x, float *y) {
    float temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    float var1, var2;

    printf("Digite o valor da variável 1: ");
    scanf("%f", &var1);

    printf("Digite o valor da variável 2: ");
    scanf("%f", &var2);

    printf("\nValores iniciais:\n");
    printf("Variável 1: %.2f\n", var1);
    printf("Variável 2: %.2f\n", var2);

    troca_valor(&var1, &var2);

    printf("\nValores após a troca:\n");
    printf("Variável 1: %.2f\n", var1);
    printf("Variável 2: %.2f\n", var2);

    return 0;
}
