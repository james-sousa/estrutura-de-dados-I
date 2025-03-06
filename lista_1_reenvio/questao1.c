#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numeros = NULL; // Ponteiro para armazenar os números
    int tamanho = 0; // Tamanho da lista de números
    int numero; // Variável para armazenar a entrada do usuário
    int somatorio = 0; // Variável para o somatório dos números
    int menor, maior; // Variáveis para o menor e o maior número

    // Solicita entradas ao usuário até que -1 seja inserido
    while (1) {
        printf("Digite um número inteiro (-1 para encerrar): ");
        scanf("%d", &numero);
        
        // Verifica se o número é -1 para encerrar a entrada
        if (numero == -1) {
            break;
        }
        
        // Realloc para aumentar o tamanho do array
        tamanho++;
        numeros = (int *)realloc(numeros, tamanho * sizeof(int));
        
        // Verifica se a alocação foi bem-sucedida
        if (numeros == NULL) {
            printf("Erro ao alocar memória.\n");
            exit(1);
        }
        
        // Armazena o número na lista
        numeros[tamanho - 1] = numero;
        
        // Atualiza o somatório
        somatorio += numero;
        
        // Atualiza o menor e o maior número, se necessário
        if (tamanho == 1 || numero < menor) {
            menor = numero;
        }
        if (tamanho == 1 || numero > maior) {
            maior = numero;
        }
    }

    // Verifica se pelo menos um número foi inserido
    if (tamanho == 0) {
        printf("Nenhum número foi inserido.\n");
    } else {
        // Calcula a média dos números
        float media = (float)somatorio / tamanho;
        
        // Imprime os resultados
        printf("Somatório: %d\n", somatorio);
        printf("Média: %.2f\n", media);
        printf("Menor número: %d\n", menor);
        printf("Maior número: %d\n", maior);
    }

    // Libera a memória alocada para o array de números
    free(numeros);

    return 0;
}
