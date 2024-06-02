/*Escreva um programa que armazene o nome dos doze meses do ano em um vetor de ponteiros
para o tipo char. Após isto, pergunte ao usuário qual o número do mês que ele nasceu e mostre
o nome do mês por extenso usando as strings armazenadas no vetor de ponteiros.*/

#include <stdio.h>

int main() {
    const char *meses[12] = {
        "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };
    
    int mes;
    
    printf("Digite o número do mês em que você nasceu (1-12): ");
    scanf("%d", &mes);
    
    if (mes < 1 || mes > 12) {
        printf("Número do mês inválido!\n");
    } else {
        printf("Você nasceu em %s.\n", meses[mes - 1]);
    }
    
    return 0;
}
