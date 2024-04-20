/*Faça um programa que leia um conjunto de 5 números inteiros que devem ser digitados pelo
usuário. Após isso, mostre os valores na tela, uns ao lado dos outros. Em seguida, faça com que os
números sejam invertidos de posição, ou seja, que o primeiro fique armazenado no lugar do último, o
segundo no lugar do penúltimo e assim por diante. Ao final, mostre novamente na tela os valores
contidos no vetor, uns ao lado dos outros.
Dica: use uma variável auxiliar para fazer a troca de posições.
// Exemplo abaixo troca os valores armazenados em V[0] e V[1] de lugar
auxiliar=V[0];
V[0]=V[1]
V[1]=auxiliar;*/

#include <stdio.h>

int main() {
    int numbers[5];
    int temp;
    
    printf("Digite 5 números inteiros:\n");
    for (int i = 0; i < 5; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    printf("\nNúmeros originais: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }

    for (int i = 0; i < 2; i++) {
        temp = numbers[i];
        numbers[i] = numbers[4 - i];
        numbers[4 - i] = temp;
    }

    printf("\nNúmeros invertidos: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
