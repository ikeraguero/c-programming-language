/*Faça uma função que recebe 2 parâmetros, x e y, e calcule a soma dos números impares entre eles
(sem contar com eles mesmos). Repare que a função deve levar em conta de que x pode ser maior
do que y. Por exemplo, para x = 6 e y = -5, temos a seguinte soma (em ordem crescente): -3 + (-1) +
1 + 3 + 5 = 5. Outro exemplo: para x = 3 e y = 10 temos 5 + 7 + 9 = 21.*/

#include <stdio.h>

int even_sum(int n1, int n2) {
    int sum = 0;
    if (n1>n2) {
        int temp = n2;
        n2 = n1;
        n1 = temp;
    }

    for (int i=n1+1; i<n2; i++) {
        if (i%2 != 0) {
            sum += i; 
        }
    }
        printf("%i \n", sum);
}

int main() {
    int x, y;
    printf("Digite dois números inteiros: ");
    scanf("%i %i", &x, &y);
    even_sum(x, y);
}