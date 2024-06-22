#include <stdio.h>
#include<unistd.h>

void init_program(int *opcao) {
    sleep(2);
    do {
        printf("======================================\n");
        printf("Bem-vindo ao Gerenciador de Músicas\n");
        printf("======================================\n");
        printf("\n");
        printf("[1] - Inserir música \n");
        printf("[2] - Remover música \n");
        printf("[3] - Listar músicas \n");
        printf("[4] - Consultar músicas \n");
        printf("\n");
        printf("Selecione a opção que deseja: ");
        scanf("%d", opcao);
        printf("\n");

    } while (*opcao <= 0 || *opcao > 4);
}

int main() {
    int opcao = 0;
    init_program(&opcao);
}