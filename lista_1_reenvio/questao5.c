#include <stdio.h>
#include <stdlib.h>

int main() {
    char vetor[] = "O EXERCICIO E FACIL";

    int tamanho = 256; // Tamanho para alocar memória para os caracteres ASCII
    int *ocorrencias = (int *)calloc(tamanho, sizeof(int)); // Alocar dinamicamente um array para contar as ocorrências

    if (ocorrencias == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    // Percorre o vetor e atualiza as ocorrências
    for (int i = 0; vetor[i] != '\0'; i++) {
        char caractere = vetor[i];
        ocorrencias[(int)caractere]++;
    }

    // Imprime as estatísticas
    for (int i = 0; i < tamanho; i++) {
        if (ocorrencias[i] > 0) {
            printf("'%c' = %d\n", (char)i, ocorrencias[i]);
        }
    }

    free(ocorrencias); // Liberar a memória alocada

    return 0;
}
