/*3) Soma de Ímpares Consecutivos I
Leia 2 valores inteiros X e Y. A seguir, calcule e mostre a soma dos números impares entre
eles.*/

#include <stdio.h>

int main() {
    int n1, n2, sum = 0;
    printf("Informe dois números inteiros: ");
    scanf("%i %i", &n1, &n2);

    if (n2 < n1) {
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }

    for (int i=n1+1; i < n2; i++) {
        if(i%2!=0) {
            sum = sum + i;
        }
    }
    printf("%i \n", sum);
}