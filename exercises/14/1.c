#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_PHONE_LENGTH 15

struct data {
    int dia;
    int mes;
    int ano;
};

struct pessoa {
    char nome[MAX_NAME_LENGTH];
    char telefone[MAX_PHONE_LENGTH];
    struct data nascimento;
};

void le_data(struct data *p) {
    printf("Digite o dia: ");
    scanf("%d", &p->dia);
    printf("Digite o mes: ");
    scanf("%d", &p->mes);
    printf("Digite o ano: ");
    scanf("%d", &p->ano);
}

void mostra_data(struct data x) {
    printf("%02d/%02d/%04d\n", x.dia, x.mes, x.ano);
}

void le_pessoa_v2(struct pessoa *p) {
    printf("Digite o nome: ");
    fgets(p->nome, MAX_NAME_LENGTH, stdin);
    p->nome[strcspn(p->nome, "\n")] = '\0';  // Remove newline character if exists

    printf("Digite o numero de telefone: ");
    fgets(p->telefone, MAX_PHONE_LENGTH, stdin);
    p->telefone[strcspn(p->telefone, "\n")] = '\0';  // Remove newline character if exists

    printf("Digite a data de nascimento:\n");
    le_data(&p->nascimento);
}

void mostra_pessoa_v2(struct pessoa x) {
    printf("Nome: %s\n", x.nome);
    printf("Telefone: %s\n", x.telefone);
    printf("Data de nascimento: ");
    mostra_data(x.nascimento);
}

int main() {
    struct pessoa p;

    le_pessoa_v2(&p);
    mostra_pessoa_v2(p);

    return 0;
}
