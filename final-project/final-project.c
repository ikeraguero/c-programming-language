#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
    int removido;
} Musica;

void adicionar_musica(Musica **musicas, int *total_musicas) {
    Musica musica;
    printf("Nome da música: ");
    scanf(" %[^\n]", musica.nome);

    for (int i=0; i<*total_musicas; i++) {
        if(!strcmp(musica.nome, (*musicas)[i].nome)) {
            printf("Erro! Música já está registrada!\n");
            return;
        }
    }

    printf("Duração (segundos): ");
    scanf("%d", &musica.duracao);
    printf("Estilo: ");
    scanf(" %[^\n]", musica.estilo);
    printf("Nome do artista: ");
    scanf(" %[^\n]", musica.artista.nome);
    printf("Nacionalidade do artista: ");
    scanf(" %[^\n]", musica.artista.nacionalidade);
    printf("Data de cadastramento (dd mm aaaa): ");
    scanf("%d %d %d", &musica.data.dia, &musica.data.mes, &musica.data.ano);
    printf("Música cadastrada com sucesso! \n");
    printf("\n");
    musica.removido = 0;

    *musicas = (Musica *)realloc(*musicas, (*total_musicas + 1) * sizeof(Musica));
    (*musicas)[*total_musicas] = musica;
    (*total_musicas)++;

}

void remover_musica(Musica *musicas, int *total_musicas) {
    char remover[50];
    printf("Qual registro deve ser apagado? (nome da música): ");
    scanf(" %[^\n]", remover);

    for (int i=0; i<*total_musicas; i++) {
        if(!strcmp(remover, musicas[i].nome)) {
            musicas[i].removido = 1;
            return;
        }
    }

    (*total_musicas)--;
}

void listar_musicas(Musica *musicas, int total_musicas) {
    printf("Listagem de Músicas Cadastradas \n");
    printf("\n");
    printf("Música               Artista              Nacionalidade        Cadastramento\n");
    printf("-------------        ---------------      ---------------      -------------  \n");
    for(int i=0; i<total_musicas; i++) {
        if(!musicas[i].removido) {
            printf("%-20s %-20s %-20s %02d/%02d/%04d\n", musicas[i].nome, musicas[i].artista.nome, musicas[i].artista.nacionalidade, musicas[i].data.dia, musicas[i].data.mes, musicas[i].data.ano);
        }
    }
    printf("\n");
}

void consultar_musica(Musica *musicas, int total_musicas){
    char consulta[50];
    printf("Qual música deseja consultar?: ");
    scanf(" %[^\n]", consulta);
    for(int i=0; i< total_musicas; i++) {
        if(!strcmp(consulta, musicas[i].nome) && !musicas[i].removido) {
            printf("Música: %s\n", musicas[i].nome);
            printf("Duração: %d segundos\n", musicas[i].duracao);
            printf("Estilo: %s\n", musicas[i].estilo);
            printf("Artista: %s\n", musicas[i].artista.nome);
            printf("Nacionalidade: %s\n", musicas[i].artista.nacionalidade);
            printf("Data de Cadastramento: %02d/%02d/%04d\n", 
                   musicas[i].data.dia, 
                   musicas[i].data.mes, 
                   musicas[i].data.ano);
            printf("\n");
        }
    }
}

int main() {
    int opcao = 0;
    Musica *musicas = NULL;
    int total_musicas = 0;

    sleep(1.5);
    while (1) {
        printf("======================================\n");
        printf("Bem-vindo ao Gerenciador de Músicas\n");
        printf("======================================\n");
        printf("\n");
        printf("[1] - Inserir música \n");
        printf("[2] - Remover música \n");
        printf("[3] - Listar músicas \n");
        printf("[4] - Consultar música \n");
        printf("[5] - Sair \n");
        printf("\n");
        printf("Selecione a opção que deseja: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 1:
                adicionar_musica(&musicas, &total_musicas);
                break;
            case 2:
                remover_musica(musicas, &total_musicas);
                break;
            case 3:
                listar_musicas(musicas, total_musicas);
                break;
            case 4:
                consultar_musica(musicas, total_musicas);
                break;
            case 5:
                free(musicas);
                return 0;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    }
}