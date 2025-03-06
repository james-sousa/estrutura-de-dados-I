#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No *criar(){
    No *novo_no = (No *)malloc(sizeof(No));
    return novo_no;
}

No *Insere_inicio(No *lista,int num){
    No *novo_no = criar();
    novo_no->reg = num;
    if (lista == NULL)
    {
        lista = novo_no;
        novo_no->prox = NULL;
    }else
    {
        novo_no->prox = lista;
        lista = novo_no;
    }
    
    return lista;
    
}

void imprimir(No *lista){
    No *aux = lista;
    while (aux != NULL)
    {
        printf("%d-",aux->reg);
        aux = aux->prox;
    }
    
}

No *insere_final(No *lista, int n){
    No *no = criar();
    no->reg = n;
    if (lista == NULL)
    {
        no->prox = NULL;
        lista = no;
    }else
    {
        No *aux = lista;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }

        no->prox = NULL;
        aux->prox =  no;
        
    }
    
    return lista;
    
}

int qtd_no(No *lista, int n){
    No *aux;
    aux = lista;
    int cont = 0;
    while (aux != NULL)
    {
        if (aux->reg == n)
        {
            cont = cont + 1;
        }
        aux = aux->prox;
        
    }
    return cont;
    
}