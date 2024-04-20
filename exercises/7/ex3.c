/*3 – Dado um vetor de inteiros, faça a busca binária de um valor (chave).
O programa deverá pedir que o usuário indique o número de elementos para o vetor. Use uma função
para inserir valores aleatórios no vetor. Com outra função, mostre os valores na tela os valores
aleatórios inseridos. Após isso, permita que o usuário digite um valor que deseja buscar no vetor.
Escreva uma função que recebe o vetor v, sua capacidade n e a chave de busca. A função deve fazer a
busca binária e indicar o índice no qual encontrou a chave. Lembre-se que a busca binária ocorre em
um vetor ordenado e será necessário fazer a ordenação antes da busca. Sugestões de protótipos de
funções:void preenche_vetor_rand(int t,int vet[t]);
void mostra_vetor(int t,int vet[t]);
void ordena_vetor(int t,int vet[t],char ordem);
int busca_binaria_chave(int t,int vet[t],int chave)*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_array_random(int size, int array[size]) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

void show_array(int size, int array[size]) {
    printf("Valores do vetor: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void sort_array(int size, int array[size]) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int binary_search_key(int size, int array[size], int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] == key)
            return mid;
        else if (array[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int size;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &size);
    
    if (size <= 0) {
        printf("O tamanho do vetor deve ser maior que zero.\n");
        return 1;
    }

    int array[size];

    fill_array_random(size, array);
    show_array(size, array);

    sort_array(size, array);
    printf("Valores do vetor após a ordenação: ");
    show_array(size, array);

    int key;
    printf("Digite o valor que deseja buscar no vetor: ");
    scanf("%d", &key);

    int index = binary_search_key(size, array, key);
    if (index != -1)
        printf("A chave %d foi encontrada no índice %d.\n", key, index);
    else
        printf("A chave %d não foi encontrada no vetor.\n", key);

    return 0;
}
