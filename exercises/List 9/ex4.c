/*Faça uma função que receba um parâmetro (por valor) com o total de minutos passados ao longo do dia
e receba também dois parâmetros (referência) no qual deve preencher com o valor da hora e do minuto
corrente. Faça um programa que leia do teclado quantos minutos se passaram desde meia-noite e
imprima a hora corrente (use a sua função).
void cacula_hora(int totalMinutos, int *ph, int *pm)*/

#include <stdio.h>

void calcula_hora(int totalMinutos, int *ph, int *pm) {
    *ph = totalMinutos / 60;
    *pm = totalMinutos % 60;
}

int main() {
    int totalMinutos, hora, minuto;

    printf("Informe quantos minutos se passaram desde meia-noite: ");
    scanf("%d", &totalMinutos);

    calcula_hora(totalMinutos, &hora, &minuto);

    printf("Hora corrente: %02d:%02d\n", hora, minuto);

    return 0;
}

