/*Fazer um programa que crie um vetor que contenha o número de dias de cada mês (veja exemplo
abaixo). O usuário deverá digitar um valor inteiro que representa o número de dias que se passaram
desde o início de 2022 e o programa deve dizer que data (dia e mês) de 2022 este valor representa.
Caso o usuário digite um número inválido (negativo, zero ou maior que 365), o programa deverá pedir
que ele digite novamente.*/

#include <stdio.h>

int main() {
    int days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int passed_days, day, month;

    do {
        printf("Digite o número de dias passados desde o início de 2022: ");
        scanf("%d", &passed_days);
    } while (passed_days <= 0 || passed_days > 365);

    int total_days = 0;
    int i;
    for (i = 0; i < 12; i++) {
        total_days += days_per_month[i];
        if (passed_days <= total_days) {
            day = passed_days - (total_days - days_per_month[i]);
            month = i + 1;
            break;
        }
    }

    printf("A data correspondente a %d dias passados desde o início de 2022 é: %d/%d/2022\n", passed_days, day, month);

    return 0;
}
