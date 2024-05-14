/*Faça uma função que calcula o perímetro e a área de um círculo, dado o raio.
void calcula_circulo(float raio, float *pPerimetro, float *pArea);*/

#include <stdio.h>

void calcula_circulo(float raio, float *pPerimetro, float *pArea) {
    *pPerimetro = 2 * 3.14159 * raio;
    *pArea = 3.14159 * raio * raio;
}

int main() {
    float raio, perimetro, area;

    printf("Digite o raio do círculo: ");
    scanf("%f", &raio);

    calcula_circulo(raio, &perimetro, &area);

    printf("Perímetro do círculo: %.2f\n", perimetro);
    printf("Área do círculo: %.2f\n", area);

    return 0;
}
