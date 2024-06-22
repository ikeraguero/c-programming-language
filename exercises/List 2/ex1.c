/* 1) Pares, Ímpares, Positivos e Negativos
Leia N valores Inteiros. A seguir mostre quantos valores digitados foram pares, quantos
valores digitados foram ímpares, quantos valores digitados foram positivos e quantos
valores digitados foram negativos.*/

#include <stdio.h>

int main() {

    int n, num, odd =0, even=0, pos=0, neg=0;
    printf("Informe a quantidade de números: ");
    scanf("%i", &n);

    for (int i = 0; i < n; i++) {
        printf("Digite o %io número: ", i+1);
        scanf("%i", &num);

        if (num%2 == 0) {
            even++;
        }
        if (num%2 != 0) {
            odd++;
        }
        if (num<0) {
            neg++;
        }
        if (num>0) {
            pos++;
        }
    }
    printf("%i valor(es) par(es) \n", even);
    printf("%i valor(es) impar(es) \n", odd);
    printf("%i valor(es) positivo(s) \n", pos);
    printf("%i valor(es) negativo(s) \n", neg);
}