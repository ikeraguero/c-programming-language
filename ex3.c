/*
3) Tempo de Jogo
Leia a hora inicial e a hora final de um jogo. A seguir calcule a duração do jogo, sabendo que
o mesmo pode começar em um dia e terminar em outro, tendo uma duração máxima de 24
horas
*/
#include <stdio.h>

int main() {
    int initial, final, duration;
    printf("Hora inicial: ");
    scanf("%i", &initial);
    printf("Hora final: ");
    scanf("%i", &final);

    if(initial > final) {
        duration = (24-initial) + final;
        printf("O JOGO DUROU %i HORAS \n", duration);
    } else if (initial == final) {
        printf("O JOGO DUROU 24 HORAS \n");
    } else if(initial < final) {
        duration = final - initial;
        printf("O JOGO DUROU %i HORAS \n", duration);
    }
}
