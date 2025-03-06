#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int M = 200; // Número de linhas
    int N = 100; // Número de colunas
    int X; // Valor máximo
    int **matriz; // Matriz M x N
    int *ocorrencias; // Array para armazenar a contagem de cada número

    // Solicitar o valor máximo X
    printf("Informe o valor máximo (X): ");
    scanf("%d", &X);

    // Alocar dinamicamente a matriz M x N
    matriz = (int **)malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++) {
        matriz[i] = (int *)malloc(N * sizeof(int));
    }

    // Alocar dinamicamente o array de ocorrencias
    ocorrencias = (int *)calloc(X + 1, sizeof(int));

    // Inicializar o gerador de números aleatórios com base no tempo
    srand(time(NULL));

    // Preencher a matriz com números aleatórios de 0 a X
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand() % (X + 1);
        }
    }

    // Contar as ocorrencias de cada número na matriz
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int valor = matriz[i][j];
            ocorrencias[valor]++;
        }
    }

    // Exibir as ocorrencias de cada número
    for (int i = 0; i <= X; i++) {
        if (ocorrencias[i] > 0) {
            printf("O número %d ocorreu %d vez%s\n", i, ocorrencias[i], ocorrencias[i] > 1 ? "es" : "");
        }
    }

    // Liberar a memória alocada
    for (int i = 0; i < M; i++) {
        free(matriz[i]);
    }
    free(matriz);
    free(ocorrencias);

    return 0;
}
