#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"

int main(int argc, char const *argv[])
{
    int cont;
    Pilha *pilha_inversa = pilha_criar();

    printf("Quantos elementos deseja armazenar?: \n");
    scanf("%d",&cont);

    float *vet = (float *)malloc(cont * sizeof(float));

    for (int i = 0; i < cont; i++)
    {
        vet[i] = rand() % 100 + 1;
    }
    for (int i = 0; i < cont; i++)
    {
        pilha_push(pilha_inversa, vet[i]);
    }
    printf("Dados originais \n");
    for (int i = 0; i < cont; i++)
    {
        printf("%.2f\n",vet[i]);
    }
    printf("Dados da pilha \n");
    mostrar_pilha(pilha_inversa);
    return 0;
}
