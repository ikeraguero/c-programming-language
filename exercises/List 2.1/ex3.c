/*Desafio: É possível fazer mais uma otimização no algoritmo para a Série de
Taylor, reescrevendo-o com somente um laço for. O resultado esperado deve
ser o mesmo do que o da 2ª versão, porém com um tempo de resposta
menor. Analise a equação utilizada na otimização e tente descobrir como
realizar o cálculo em um único laço de repetição*/

#include <stdio.h>

int main() {
    float x;
    int n;
    printf("Digite x e a quantidade de termos n: ");
    scanf("%f%d", &x, &n);
    
    float e_x = 1; // Começa com o primeiro termo da série de Taylor
    
    float termo = 1;
    for (int i = 1; i <= n; i++) {
        termo *= x / i; // Calcula o próximo termo baseado no anterior
        e_x += termo; // Acumula o próximo termo no resultado
    }

    printf("e elevado a %.3f = %.8f\n", x, e_x);
    return 0;
}