#include <stdio.h>

int main() {
    float x;
    int n, i, j;
    printf("Digite x e a quantidade de termos n: ");
    scanf("%f%d", &x, &n);
    float e_x = 0; // inicializa somatório com zero
    for( i = 0 ; i <= n ; i++ ){ // gera os termos
        float termo = 1;
        for( j = 1 ; j <= i ; j++ ){
            termo = termo * x / j;
        }
    e_x = e_x + termo; // Acumula termo no somatório
}

    printf("e elevado a %.3f = %.8f\n", x, e_x);
}