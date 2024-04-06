/*Escreva uma função que recebe dois vetores de mesma capacidade n e compara se os mesmos são iguais,
ou seja, se contêm os mesmos valores e na mesma ordem. A função deve ser booleana, ou seja, se forem
iguais retorna 1, caso contrário retorna 0. Protótipo da função:*/

#include <stdio.h>

int equal_arrays(float a[], float b[], int n) {
    for (int i=0; i<n; i++) {
        if (a[i]!=b[i]) {
            return 0;
        }

    }
    return 1;
} 

int main() {
    float a[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float b[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int n = sizeof(a) / sizeof(a[0]);
    equal_arrays(a, b, n);
}