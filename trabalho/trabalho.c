#include <stdio.h>
#include <unistd.h>

/*O programa deve ficar em um ciclo de repetições, oferecendo um menu de texto com as seguintes opções
ao usuário ✅*/
void init_program(int *opcao) {
    sleep(2);
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
            matriz[i][j] = 0;
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
    if (*contador < m) {
        (*contador)++;
        printf("Novo conjunto criado! Total de conjuntos: %d\n", *contador);
        printf("\n");
    } else {
        printf("Número máximo de conjuntos atingido!\n");
    }
}

/*Inserir dados em um conjunto: o usuário deve informar o índice i do conjunto em que deseja fazer a
inserção (1 ≤ i ≤ contador); os demais requisitos devem ser respeitados:
a) O usuário pode inserir vários valores na sequência; o processo se encerra quando é digitado o valor
zero ou quando se atingiu a quantidade N (número de colunas da matriz); ✅*/
void inserir_dados(int m, int n, int conjunto[m][n]) {
    int valor, j;
    if (m == 0) {
        printf("\n");
        printf("Informe um número válido (1 a 10)\n ");
        printf("\n");
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
                printf("\nVoltando ao menu inicial... \n");
                sleep(2);
                printf("\n");
            }
            if (j == 0) {
                printf("Limite máximo do conjunto atingido!\n");
            }
            break;
        }
    sleep(2);
    }
}

int conjunto_existe(int conj, int contador) {
    return conj <= contador && conj > 0 ? 1 : 0;
}

/*Remover um conjunto: o usuário deve informar o índice i do conjunto em que deseja fazer a inserção (0
≤ i < contador); a linha i deve ser zerada, e deve-se mover os conjuntos abaixo dele para reorganizar a
matriz, decrementando-se o contador (pois há um conjunto a menos); por exemplo, tem-se 10 conjuntos
e o usuário deseja remover o conjunto 6; neste caso, a linha 6 é zerada, os conjuntos (linhas da matriz)
de 7 a 9 são movidos “para cima”, e o contador é decrementado para 9; ✅*/

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
        printf("Conjunto %i removido com sucesso!\n", conjunto_index + 1); // Increment index by 1
    } else {
        printf("Índice do conjunto inválido!\n");
    }
}

/*Fazer a união entre dois conjuntos: o usuário deve informar os índices dos conjuntos que fazem parte
dessa operação; o conjunto resultante é adicionado à matriz de conjuntos como uma nova linha da
matriz; ✅*/

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

/*Fazer a intersecção entre dois conjuntos: idem à operação anterior;✅*/


void faz_intersecao(int *contador, int m, int n, int conjuntos[m][n]) {
    int indice1, indice2;
    printf("Informe os índices dos dois conjuntos para fazer a interseção: ");
    scanf("%d %d", &indice1, &indice2);
    if (indice1 > 0 && indice1 <= *contador && indice2 > 0 && indice2 <= *contador) {
        int novo_conjunto[n];
        int index_novo_conjunto = 0;
        for (int i = 0; i < n && conjuntos[indice1 - 1][i] != 0; i++) {
            int value = conjuntos[indice1 - 1][i];
            int found = 0;
            for (int j = 0; j < n && conjuntos[indice2 - 1][j] != 0; j++) {
                if (conjuntos[indice2 - 1][j] == value) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                novo_conjunto[index_novo_conjunto++] = value;
            }
        }
        for (int i = 0; i < n; i++) {
            conjuntos[*contador][i] = novo_conjunto[i];
        }
        (*contador)++;
        printf("Interseção realizada com sucesso! Novo conjunto adicionado.\n");
    } else {
        printf("Índices de conjunto inválidos.\n");
    }
}

/*Mostrar um conjunto, dado o seu índice;✅*/

void mostra_conjunto(int m, int n, int conjuntos[m][n], int *contador, int indice) {
    if (conjunto_existe(indice, *contador)) {
        printf("Mostrando conjunto %i: ", indice);
        for (int j = 0; j < n; j++) {
            printf("%i", conjuntos[indice - 1][j]);
        }
        printf("\n");
    } else {
        printf("Informe um conjunto existente\n");
    }
}

/*Mostrar todos os conjuntos; ✅*/

void mostra_todos_conjuntos(int m, int n, int conjuntos[m][n], int *contador) {
    for(int i=1; i<=*contador; i++) {
        mostra_conjunto(m, n, conjuntos, contador, i);
    }
    if(*contador==0) {
        printf("Nenhum conjunto existente!\n");
    }
}

/*Busca por um valor: dado um valor, deve-se mostrar os índices dos conjuntos que contenham esse valor;; ✅*/

void mostra_indice(int m, int n, int conjuntos[m][n], int *contador) {
    int valor;
    int count = 0;
    printf("Informe o valor que deseja encontrar: ");
    scanf("%i", &valor);
    printf("Conjuntos que possuem esse valor: \n");
    for(int i=0; i<*contador; i++) {
        for(int j=0; j<n; j++) {
            if(conjuntos[i][j] == valor) {
                count++;
                printf("Conjunto %i \n", i+1);
                break;
            }
        }
    }
    if(count==0) {
        printf("Nenhum! \n");
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
            printf("\n");
            printf("Por favor, insira um número válido!\n");
            printf("\n");

        }

        if (opcao == 1) {
            criar_conjunto(&contador, m);
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
        if (opcao == 5) {
            faz_intersecao(&contador, m, n, conjuntos);
        }
        if (opcao == 6) {
            int indice;
            printf("Informe o número do conjunto: ");
            scanf("%i", &indice);
            mostra_conjunto(m, n, conjuntos, &contador, indice);
        }
        if (opcao == 7) {
            mostra_todos_conjuntos(m, n, conjuntos, &contador);
        }
        if (opcao ==8) {
            mostra_indice(m, n, conjuntos, &contador);
        }
    } while (opcao != 9);
    printf("Encerrando o programa...\n");
    sleep(2); 
    return 0;
}
