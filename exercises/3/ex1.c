/*1) Faça um programa que lê os três lados de um triângulo e determina o seu tipo, conforme códigos a
seguir. Os códigos devem ser retornados por uma função de tipo int, que recebe os lados do
triângulo como parâmetro. Protótipo da função:
int tipo_triangulo(float, x, float y, float z);
O retorno da função deve ser conforme os códigos a seguir:
0. Os lados não formam um triângulo (ou seja, a soma de dois deles é menor ou igual ao outro
lado);
1. Triângulo equilátero;
2. Triângulo isóceles;
3. Triângulo escaleno.*/

#include <stdio.h>

int triangle_type(float n1, float n2, float n3) {
        if (n1==n2 && n2==n3) {
            printf("Triangulo equilátero \n");
            return 1;
        }
        else if (n1==n2 && n2 != n3 || n1 == n3 && n3 != n2 || n2 == n3 && n3!=n1) {
            printf("Triangulo isósceles \n");
            return 1;
        }
        else if(n1 != n2 && n2 != n3) {
            printf("Triangulo escaleno \n");
            return 1;
        }
        return 0;
    };

int main() {
    float n1, n2, n3;
    do {
    printf("Digite os três lados de um triangulo: ");
    scanf("%f %f %f", &n1, &n2, &n3);
    } while (n1 <= 0 || n2 <= 0 || n3 <=0);
    triangle_type(n1, n2, n3);
}