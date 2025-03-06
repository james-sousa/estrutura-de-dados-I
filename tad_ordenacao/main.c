#include <stdio.h>
#include <stdlib.h>
#include "tad_ordemacao.c"
#include <time.h>
int main(){
    Ordem vet;
    int tamanho;
    clock_t t;
    int opc;

    printf("Digite o tamanho do vetor: \n");
    scanf("%d",&tamanho);
    inicializar(&vet,tamanho);
    preencherVetor(&vet);
    printf("Vetor sem ordenar:\n");
    imprimir(&vet);
    printf("Qual o algoritimo de ordenação que deseja usar\n1-Bubble sort\n2-Insertion Sort\n3-Selection sort: \n");
    scanf("%d",&opc);
    switch (opc)
    {
    case 1:
        printf("Ordenando com bubble sort\n");
        t = clock();
        bubble_sort(&vet);
        t = clock() - t;
        printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
        printf("vetor ordenado:\n");
        
        free(vet.num);
        break;
    case 2:
        printf("Ordenando com Insertion sort\n");
        t = clock();
        insertion_sort(&vet);
        t = clock() - t;
        printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
        printf("vetor ordenado:\n");
        
        free(vet.num);
        break;
    case 3:
        printf("Ordenando com Selection sort\n");
        t= clock();
        selection_sort(&vet);
        t = clock() - t;
        printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
        printf("vetor ordenado:\n");
        
        free(vet.num);
    default:
        break;
    }
  
    return 0;
}
