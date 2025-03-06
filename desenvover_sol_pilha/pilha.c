#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


struct no{
    float info;
    struct no *prox;
};

struct pilha{
    No *pil;
};

Pilha *pilha_criar(){
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->pil = NULL;
    return p;
}

void pilha_push(Pilha *p, float v){
    No *n = (No *)malloc(sizeof(No));
    n->info = v;
    n->prox = p->pil;
    p->pil = n;
}

float pilha_pop(Pilha *p){
    No *aux;
    float v;
    if (pilha_vazia(p))
    {
        printf("Pilha vazia\n");
        exit(1);
    }
    aux = p->pil;
    v = aux->info;
    p->pil = aux->prox;
    free(aux);
    return v;
}

void pilha_libera(Pilha *p){
    No *aux = p->pil;
    while (aux!=NULL)
    {
        No *aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(p);
    
}

int pilha_vazia(Pilha *p){
    if (p->pil == NULL)
    {
        return 1;
    }

    return 0;
    
}

void mostrar_pilha(Pilha *p){
    No *aux = p->pil;
    while (aux != NULL)
    {
        printf("%.2f\n",aux->info);
        aux = aux->prox;
    }
    
}