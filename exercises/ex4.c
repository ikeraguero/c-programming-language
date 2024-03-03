/* 4) Número de Dias
Leia o dia e o mês em que um evento irá ocorrer neste ano. A seguir calcule o número de
dias que passarão desde o início do ano (01 de janeiro) até o dia do evento. Considere o
número de dias precisos que há em cada mês e suponha que o ano não seja bissexto.*/

#include <stdio.h>

int main() {
    int day, month, totaldays;
    printf("Informe o dia: ");
    scanf("%i", &day);
    printf("Informe o mês: ");
    scanf("%i", &month);

    switch (month-1)
    {
        case 11:
            totaldays += 30;
        case 10:
            totaldays += 31;
        case 9:
            totaldays += 30;
        case 8:
            totaldays += 31;
        case 7:
            totaldays += 31;
        case 6:
            totaldays += 30;
        case 5:
            totaldays += 31;
        case 4:
            totaldays += 30;
        case 3:
            totaldays += 31;
        case 2:
            totaldays += 28; 
        case 1:
            totaldays += 31;
    }
totaldays += day;

if (month==1) {
    printf("%i DIA(S) DO INICIO DO ANO ATE O EVENTO \n", day);
} else {
    printf("%i DIA(S) DO INICIO DO ANO ATE O EVENTO \n", totaldays);
}
}
