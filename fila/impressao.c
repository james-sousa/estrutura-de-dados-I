#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da fila
typedef struct No {
    int id;
    struct No *prox;
} No;

// Definindo a estrutura da fila
typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

// Inicializa a fila
void inicializarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

// Verifica se a fila está vazia
int estaVazia(Fila *fila) {
    return fila->tamanho == 0;
}

// Obtém o tamanho da fila
int obterTamanho(Fila *fila) {
    return fila->tamanho;
}

// Enfileira um documento na fila
void enfileirar(Fila *fila, int idDocumento) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro ao alocar memória para novo nó.\n");
        exit(EXIT_FAILURE);
    }

    novoNo->id = idDocumento;
    novoNo->prox = NULL;

    if (estaVazia(fila)) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }

    fila->tamanho++;
}

// Simula a impressão, retirando um documento da fila
void imprimirDocumento(Fila *fila) {
    if (estaVazia(fila)) {
        printf("Nenhum documento para imprimir. Fila vazia.\n");
    } else {
        No *temp = fila->inicio;
        printf("Imprimindo documento com ID %d.\n", temp->id);

        fila->inicio = temp->prox;
        free(temp);

        fila->tamanho--;

        if (estaVazia(fila)) {
            fila->fim = NULL;
        }
    }
}

// Libera a memória alocada para a fila
void liberarFila(Fila *fila) {
    while (!estaVazia(fila)) {
        No *temp = fila->inicio;
        fila->inicio = temp->prox;
        free(temp);
    }

    fila->fim = NULL;
}

int main() {
    Fila filaImpressao;
    inicializarFila(&filaImpressao);

    enfileirar(&filaImpressao, 1);
    enfileirar(&filaImpressao, 2);
    enfileirar(&filaImpressao, 3);

    printf("Tamanho da fila: %d\n", obterTamanho(&filaImpressao));

    imprimirDocumento(&filaImpressao);
    imprimirDocumento(&filaImpressao);
    imprimirDocumento(&filaImpressao);

    printf("Tamanho da fila: %d\n", obterTamanho(&filaImpressao));

    liberarFila(&filaImpressao);

    return 0;
}
