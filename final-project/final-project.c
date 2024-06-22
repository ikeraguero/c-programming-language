#include <stdio.h>
#include<unistd.h>

typedef struct {
    char nome[50];
    char nacionalidade[20];
} Artista;

typedef struct 
{
    int dia;
    int mes;
    int ano;
} Data;


typedef struct {
    char nome[50];
    int duracao;
    char estilo[20];
    Artista artista;
    Data data;
} Musica;

void adicionar_musica() {
    printf("Adicionar\n");
}

void remover_musica() {
    printf("Remover\n");
}

void listar_musicas() {
    printf("Listar\n");
}

void consultar_musica(){
    printf("Consultar\n");
}

int main() {
    int opcao = 0;
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
        scanf("%d", &opcao);
        printf("\n");

    } while (opcao <= 0 || opcao > 4);

    if(opcao==1) {
        adicionar_musica();
    }
    if(opcao==2) {
        remover_musica();
    }
    if(opcao==3) {
        listar_musicas();
    }
    if(opcao==4) {
        consultar_musica();
    }
}