#include <stdio.h>
#include <stdlib.h>
#include "tad_ordenacao.h"
#include <time.h>

void inicializar(Ordem *vet, int tam){
    vet->tam = tam;
    vet->num = (int *)malloc(tam * sizeof(int));

}

int geraNumero(){
    return rand() % 100000;
}
void preencherVetor(Ordem *vet){
    srand(time(NULL));
    for (int i = 0; i < vet->tam; i++)
    {
        vet->num[i] = geraNumero();
    }
    
}
void imprimir(Ordem *vet){
    for (int i = 0; i < vet->tam; i++)
    {
        printf("N: %d\n",vet->num[i]);
    }
    printf("\n");
    
}

void bubble_sort(Ordem *vet){
    int aux,i,troca;
    unsigned long long int quant_troca=0;
    unsigned long long int quant_comparacoes = 0;
    troca = 1;
    while (troca == 1)
    {
        troca = 0;
        for ( i = 0; i <= vet->tam - 2; i++)
        {   quant_comparacoes++;
            if (vet->num[i] > vet->num[i + 1])
            {
                aux = vet->num[i];
                vet->num[i] = vet->num[i + 1];
                vet->num[i + 1] = aux;
                troca = 1;
                quant_troca++;
            }
            
        }
        
    }
    printf("Quantidade de comparações: %lld\n",quant_comparacoes);
    printf("Quantide de trocas: %lld\n",quant_troca); 
    
}

void insertion_sort(Ordem *vet){
    int i,j,tmp;
    long long int quant_troca=0;
    long long int quant_comparacao=0;

    for ( i = 0; i < vet->tam; i++)
    {
        tmp = vet->num[i];

        for ( j = i-1; j >=0 && tmp < vet->num[j]; j--)
        {
            vet->num[j+1] = vet->num[j];
            quant_comparacao++;
            quant_troca++;
        }
        
        vet->num[j+1] = tmp;
        
    }
    printf("Quantidade de comparação: %lld\n",quant_comparacao);
    printf("Quantidade de trocas: %lld\n",quant_troca);
}

void trocar(int *v1, int *v2) {
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

// Função de seleção usando a TAD do vetor
void selection_sort(Ordem *vet) {
    int i, j, indice_minimo,quant_trocas=0;
    int quant_comparacao=0;

    // Percorre o vetor
    for (i = 0; i < vet->tam-1; i++) {
        // Encontra o menor elemento no vetor não ordenado
        indice_minimo = i;
        for (j = i+1; j < vet->tam; j++)
            quant_comparacao++;
            if (vet->num[j] < vet->num[indice_minimo])
                indice_minimo = j;

        // Troca o menor elemento com o primeiro elemento não ordenado
        trocar(&vet->num[indice_minimo], &vet->num[i]);
        quant_trocas++;
    }
    printf("Quantidade de comparações: %d\n",quant_comparacao);
    printf("Quantidade de trocas: %d\n",quant_trocas);
}
