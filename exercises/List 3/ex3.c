/*Escreva um programa que informa se um caractere digitado pelo usuário representa um dígito de
0 a 9. A verificação deve ser feita por uma função booleana (int) que recebe um char como
parâmetro. Caso o caractere seja um dígito, converta-o para um valor inteiro e o armazene em uma
variável int. Em seguida, mostre o valor inteiro na tela.*/

#include <stdio.h>

int is_digit(char input) {
    if (input >= '0' && input <= '9' ){
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char input;
    printf("Digite um caractere: ");
    scanf(" %c", &input);

    if(is_digit(input)) {
        int input_int = input - '0';
        printf("O valor digitado representa o digito inteiro %i \n", input_int);
    } else {
        printf("O valor digitado não representa um dígito inteiro \n");
    }
}