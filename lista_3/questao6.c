#include <stdio.h>

// Função para pesquisa sequencial
int searchSequential(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;  // Retorna a posição onde o valor foi encontrado
        }
    }
    return -1;  // Retorna -1 se o valor não for encontrado no vetor
}

int main() {
    int array[] = {2, 4, 6, 8, 10, 12, 14};
    int size = sizeof(array) / sizeof(array[0]);
    int searchValue = 10;

    int result = searchSequential(array, size, searchValue);

    if (result != -1) {
        printf("O valor %d foi encontrado na posição %d do vetor.\n", searchValue, result);
    } else {
        printf("O valor %d não foi encontrado no vetor.\n", searchValue);
    }

    return 0;
}
