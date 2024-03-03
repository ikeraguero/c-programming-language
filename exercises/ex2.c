/* 2) Tipos de Triângulos
Leia 3 valores de ponto flutuante A, B e C e ordene-os em ordem decrescente, de modo que
o lado A representa o maior dos 3 lados. A seguir, determine o tipo de triângulo que estes
três lados formam, com base nos seguintes casos, sempre escrevendo uma mensagem
adequada:
• se A ≥ B+C, apresente a mensagem: NAO FORMA TRIANGULO
• se A2 = B2 + C2, apresente a mensagem: TRIANGULO RETANGULO
• se A2 > B2 + C2, apresente a mensagem: TRIANGULO OBTUSANGULO
• se A2 < B2 + C2, apresente a mensagem: TRIANGULO ACUTANGULO
• se os três lados forem iguais, apresente a mensagem: TRIANGULO EQUILATERO
• se apenas dois dos lados forem iguais, apresente a mensagem: TRIANGULO
ISOSCELES*/

#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    printf("Informe o primeiro valor: ");
    scanf("%f", &a);
    printf("Informe o segundo valor: ");
    scanf("%f", &b);
    printf("Informe o terceiro valor: ");
    scanf("%f", &c);

    if (a<b) {
        float temp = a;
        a= b;
        b = temp;
    }

    if (a<c) {
        float temp = a;
        a = c;
        c = temp;
    };
     if (b < c) {
        float temp = b;
        b = c;
        c = temp;

    }
    
    if(a >= b+c) {
        printf("NÃO FORMA TRIANGULO \n");
    }
    else if(pow(a, 2) == pow(b, 2) + pow(c,2)) {
        printf("TRIANGULO RETANGULO \n");
    }
    else if(pow(a, 2) > pow(b, 2) + pow(c,2)) {
        printf("TRIANGULO OBTUSANGULO \n");
    }
    else if(pow(a, 2) < pow(b, 2) + pow(c,2)) {
        printf("TRIANGULO ACUTANGULO \n");
    }

    if(a == b && b == c) {
        printf("TRIANGULO EQUILATERO \n");
    }
    if(a==b && a !=c || b==c && b!=a || a==c && a!=b ) {
        printf("TRIANGULO ISOSCELES \n");
    }
}