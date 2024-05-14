/*Faça uma função que recebe dois números, a e b. A função deve incrementar a e decrementar b.
void inc_dec (int *a, int *b)*/

#include <stdio.h>

void inc_dec(int *num_a, int *num_b) {
    (*num_a)++;
    (*num_b)--;
}

int main() {
    int a = 5, b = 10;
    printf("Valores iniciais: a = %d, b = %d\n", a, b);
    inc_dec(&a, &b);
    printf("Valores após a função: a = %d, b = %d\n", a, b);

    return 0;
}
