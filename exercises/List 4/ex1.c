/*Escreva uma função que calcula o somatório dos n termos que são múltiplos de k a partir de x. Os
parâmetros são determinados pelo usuário e a função é chamada pelo programa principal, que
em seguida mostra o resultado na tela. Exemplo: para n = 3, k = 4 e x = 18, temos, 20 + 24 + 28 =
72. Protótipo da função: int soma_especial(int n, int k, int x);*/

#include <stdio.h>

int special_sum(int n, int k, int x) {
   if (n==0) {
    return 0;
   }

   if(x%k == 0 ) {
    return x + special_sum(n - 1, k, x + 1);
   } else {
    return special_sum(n, k, x+1);
   }
};

int main() {
    int n, k, x, sum;
    printf("Informe n, k e x respectivamente: ");
    scanf("%i" "%i" "%i", &n, &k, &x);
    sum = special_sum(n, k, x);
    printf("%i", sum);
}