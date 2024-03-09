/*2) Médias Ponderadas
Leia 1 valor inteiro N, que representa o número de casos de teste que vem a seguir. Cada
caso de teste consiste de 3 valores reais, cada um deles com uma casa decimal. Apresente
a média ponderada para cada um destes conjuntos de 3 valores, sendo que o primeiro
valor tem peso 2, o segundo valor tem peso 3 e o terceiro valor tem peso 5.

10 -- 2     x = 2y/10
y --- x

*/

#include <stdio.h>

int main() {

    int n;
    float num, avg, sum;
    printf("Informe o número de testes: ");
    scanf("%i", &n);

    for (int i=1; i<=n; i++) {
        sum = 0;
        for (int j=1; j<=3; j++) {
            printf("Informe o %io valor: ", j);
            scanf("%f", &num);
            
            if (j==1) {
                avg = (2*num)/10;
            }
            else if (j==2) {
                avg = (3*num)/10;
            }
            else if (j==3) {
                avg = (5*num)/10;
            }

            sum = sum+avg;
        }
        printf("%f \n", sum);
    }
}