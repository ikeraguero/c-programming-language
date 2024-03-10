/*4) Soma de Ímpares Consecutivos II
Leia um valor inteiro N que é a quantidade de casos de teste que vem a seguir. Cada caso
de teste consiste de dois inteiros X e Y. Você deve apresentar a soma de todos os ímpares
existentes entre X e Y.*/

#include <stdio.h>

int main() {
    int n, num1, num2, sum =0;
    printf("Informe a quantidade de testes: ");
    scanf("%i", &n);

    for(int i=0; i < n; i++) {
        sum = 0;
        printf("Informe dois valores inteiros: ");
        scanf("%i %i", &num1, &num2);

        if (num2<num1) {
            int temp = num2;
            num2 = num1;
            num1 = temp;
        }

        for (int j=num1+1; j < num2; j++) {
            if(j%2!=0) {
                sum = sum + j;
            }
        }
            printf("%i \n", sum);
    }
}