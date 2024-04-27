#include <stdio.h>



/*O programa deve ficar em um ciclo de repetições, oferecendo um menu de texto com as seguintes opções
ao usuário ✅*/
void init_program(int *opcao) {
        do {
    printf("======================================\n");
    printf("Bem-vindo ao Gerenciador de Conjuntos!\n");
    printf("======================================\n");
    printf("\n");
    printf("Selecione a opção que deseja: \n");
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
    scanf("%d", opcao);
    } while (*opcao <= 0 || *opcao > 9);
}


/*A matriz deve ser inicializada com zeros, indicando que está vazia. O zero, portanto, não é considerado como
um valor válido ✅*/ 
void init_matriz(int m, int n, int matriz[m][n]) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
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
    *contador < m ? (*contador)++ && printf("Novo conjunto criado. Total de conjuntos: %d\n", *contador) : printf("Número máximo de conjuntos atingido!\n");
}


/*Inserir dados em um conjunto: o usuário deve informar o índice i do conjunto em que deseja fazer a
inserção (0 ≤ i < contador); os demais requisitos devem ser respeitados:
a) O usuário pode inserir vários valores na sequência; o processo se encerra quando é digitado o valor
zero ou quando se atingiu a quantidade N (número de colunas da matriz); ✅*/
void inserir_dados(int m, int n, int conjunto[m][n]) {
    int valor, j;
    if(m==0) {
        printf("Informe um número válido (1 a 10)\n ");
        return;
    }
        for (j=n-1; j>=0; j--) {
            do {
            printf("Informe o valor que deseja adicionar à casa %i do conjunto %i: ", j+1, m);
            scanf("%i", &valor);
            } while (valor < 0);
            conjunto[m-1][j] = valor;
            if (valor == 0 || j == 0) {
                if (valor==0) {
                    printf("\nVoltando ao menu inicial! \n");
                    printf("\n");
                }
                if (j==0) {
                    printf("Limite máximo do conjunto atingido!\n");
                }
                break;
            }
}
}

int conjunto_existe(int conj, int contador) {
    return conj <= contador ? 1 : 0;
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
        printf("Conjunto %i removido com sucesso!\n", conjunto_index + 1);
    } else {
        printf("Índice do conjunto inválido!\n");
    }
}

int main() {

    // Definindo dimensões da matriz
    int m =10, n=10;
    int conjuntos[m][n];
    int opcao = 0, contador = 0;

    init_matriz(m, n, conjuntos);
    init_contador(&contador);
    do {
    init_program(&opcao);

    if(opcao<=0 || opcao>9) {
        printf("Por favor, insira um número válido!");
    }

    if(opcao==1) {
        criar_conjunto(&contador, m);
        printf("%i\n", contador);
        opcao = 0;
    }

    if(opcao==2) {
       if (contador < m) {
            int conj;
            printf("Informe qual conjunto deseja preencher: ");
            scanf("%i", &conj);
            if (conjunto_existe(conj, contador)) {
                inserir_dados(conj, n, conjuntos);
            } else {
                printf("Por favor informe um conjunto já criado!\n");
            }
            } else {
                printf("Número máximo de conjuntos atingidos!\n");
            }
        }
    if(opcao==3) {
        int conj;
        printf("Informe qual conjunto deseja remover: ");
        scanf("%i", &conj);
        if(conjunto_existe(conj, contador)) {
            remove_conjunto(&contador, m, n, conjuntos, conj -1);
        } else {
                printf("Por favor informe um conjunto já criado!\n");
        }
    }
    } while (opcao != 9);   
}