#include <stdio.h>

/*O programa deve ficar em um ciclo de repetições, oferecendo um menu de texto com as seguintes opções
ao usuário ✅*/
void init_program(int *opcao) {
    do {
        printf("======================================\n");
        printf("Bem-vindo ao Gerenciador de Conjuntos!\n");
        printf("======================================\n");
        printf("\n");
        printf("[1] - Criar um novo conjunto vazio \n");
        printf("[2] - Inserir dados em um conjunto \n");
        printf("[3] - Remover um conjunto \n");
        printf("[4] - Fazer união entre dois conjuntos \n");
        printf("[5] - Fazer a intersecção entre dois conjuntos \n");
        printf("[6] - Mostrar um conjunto \n");
        printf("[7] - Mostrar todos os conjuntos \n");
        printf("[8] - Buscar por um valor \n");
        printf("[9] - Sair do programa \n");
        printf("\n");
        printf("Selecione a opção que deseja: ");
        scanf("%d", opcao);
        printf("\n");

    } while (*opcao <= 0 || *opcao > 9);
}

/*A matriz deve ser inicializada com zeros, indicando que está vazia. O zero, portanto, não é considerado como
um valor válido ✅*/
void init_matriz(int m, int n, int matriz[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = -1; // Use -1 to indicate an empty cell
        }
    }
}

/*Além da matriz, o programa deve utilizar um contador para registrar quantidade de conjuntos. Portanto, o
contador também deve estar zerado ao início do programa. ✅*/
void init_contador(int *contador) {
    *contador = 0;
}

/* Criar um novo conjunto vazio: basta incrementar o contador, caso seja menor que M;✅*/
/* Não deve ser possível criar mais do que M conjuntos ✅*/
void criar_conjunto(int *contador, int m) {
    *contador < m ? (*contador)++ && printf("Novo conjunto criado. Total de conjuntos: %d\n", *contador) : printf("Número máximo de conjuntos atingido!\n");
}

/*Inserir dados em um conjunto: o usuário deve informar o índice i do conjunto em que deseja fazer a
inserção (1 ≤ i ≤ contador); os demais requisitos devem ser respeitados:
a) O usuário pode inserir vários valores na sequência; o processo se encerra quando é digitado o valor
zero ou quando se atingiu a quantidade N (número de colunas da matriz); ✅*/
void inserir_dados(int m, int n, int conjunto[m][n]) {
    int valor, j;
    if (m == 0) {
        printf("Informe um número válido (1 a 10)\n ");
        return;
    }
    for (j = n - 1; j >= 0; j--) {
        do {
            printf("Informe o valor que deseja adicionar à casa %i do conjunto %i: ", j + 1, m);
            scanf("%i", &valor);
        } while (valor < 0);
        conjunto[m - 1][j] = valor;
        if (valor == 0 || j == 0) {
            if (valor == 0) {
                printf("\nVoltando ao menu inicial! \n");
                printf("\n");
            }
            if (j == 0) {
                printf("Limite máximo do conjunto atingido!\n");
            }
            break;
        }
    }
}

int conjunto_existe(int conj, int contador) {
    return conj <= contador && conj > 0 ? 1 : 0;
}

void remove_conjunto(int *contador, int m, int n, int conjuntos[m][n], int conjunto_index) {
    if (conjunto_index >= 0 && conjunto_index < *contador) {
        for (int j = 0; j < n; j++) {
            conjuntos[conjunto_index][j] = 0;
        }

        for (int i = conjunto_index + 1; i < *contador; i++) {
            for (int j = 0; j < n; j++) {
                conjuntos[i - 1][j] = conjuntos[i][j];
            }
        }

        for (int j = 0; j < n; j++) {
            conjuntos[*contador - 1][j] = 0;
        }
        (*contador)--;
        printf("Conjunto %i removido com sucesso!\n", conjunto_index);
    } else {
        printf("Índice do conjunto inválido!\n");
    }
}

void faz_uniao(int *contador, int m, int n, int conjuntos[m][n]) {

    int indice1, indice2;

    printf("Informe os índices dos dois conjuntos para fazer a união: ");
    scanf("%d %d", &indice1, &indice2);

    if (indice1 > 0 && indice1 <= *contador && indice2 > 0 && indice2 <= *contador) {
        int novo_conjunto[n];
        int index_novo_conjunto = 0;

        for (int i = 0; i < n; i++) {
            novo_conjunto[i] = 0;
        }

        for (int i = 0; i < n && conjuntos[indice1 - 1][i] != 0; i++) {
            novo_conjunto[index_novo_conjunto++] = conjuntos[indice1 - 1][i];
        }

        for (int i = 0; i < n && conjuntos[indice2 - 1][i] != 0; i++) {
            int value = conjuntos[indice2 - 1][i];
            int found = 0;
            for (int j = 0; j < index_novo_conjunto; j++) {
                if (novo_conjunto[j] == value) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                novo_conjunto[index_novo_conjunto++] = value;
            }
        }

        for (int i = 0; i < n; i++) {
            conjuntos[*contador][i] = novo_conjunto[i];
        }

        (*contador)++;
        printf("União realizada com sucesso! Novo conjunto adicionado.\n");
    } else {
        printf("Índices de conjunto inválidos.\n");
    }
}

int main() {

    // Definindo dimensões da matriz
    int m = 10, n = 10;
    int conjuntos[m][n];
    int opcao = 0, contador = 0;

    init_matriz(m, n, conjuntos);
    init_contador(&contador);
    do {
        init_program(&opcao);

        if (opcao <= 0 || opcao > 9) {
            printf("Por favor, insira um número válido!\n");
        }

        if (opcao == 1) {
            criar_conjunto(&contador, m);
            printf("%i\n", contador);
            opcao = 0;
        }

        if (opcao == 2) {
            if (contador < m) {
                int conj;
                printf("Informe qual conjunto deseja preencher: ");
                scanf("%i", &conj);
                if (conjunto_existe(conj, contador)) {
                    inserir_dados(conj, n, conjuntos);
                } else {
                    printf("Por favor, informe um conjunto válido!\n");
                }
            } else {
                printf("Número máximo de conjuntos atingidos!\n");
            }
        }
        if (opcao == 3) {
            int conj;
            printf("Informe qual conjunto deseja remover: ");
            scanf("%i", &conj);
            if (conjunto_existe(conj, contador)) {
                remove_conjunto(&contador, m, n, conjuntos, conj - 1);
            } else {
                printf("Por favor, informe um conjunto válido!\n");
            }
        }
        if (opcao == 4) {
            faz_uniao(&contador, m, n, conjuntos);
        }
    } while (opcao != 9);
    return 0;
}
