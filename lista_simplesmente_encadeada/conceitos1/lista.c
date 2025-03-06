#include <stdio.h>
#include <stdlib.h>
#include "lista.h"



def_lista cria_no(){
    def_lista *no = (def_lista *)malloc(sizeof(def_lista));
    return no;
}

def_lista *insere_inicio(def_lista *Lista, int nro){
    def_lista *no = cria_no();
    no
    if (Lista != NULL)
    {
        no->prox = *Lista;
        *Lista = no;
    }
    printf("valor inserido\n");
    return no;
}

def_lista *insere_final(def_lista* Lista, int nro){
    def_lista *no = cria_no();
    
    if (Lista == NULL)
    {
        Lista = no;
        no->prox = NULL;
        
    }else
    {
        aux = *Lista;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
            aux->prox = no;
        }
        
    }
    
    return Lista;
    
}

int busca(def_lista Lista, int nro){
    def_lista aux;
    for ( aux = Lista; aux != NULL; aux=aux->prox)
    {
        if (aux->info == nro)
        {
            return 1;
        }
        
    }

    return 0;
    
}

void imprime_lista(def_lista Lista){
    def_lista aux = Lista;
    while (aux != NULL)
    {
        printf("%d-\t",aux->info);
        aux = aux->prox;
    }
    

    printf("\n");
    
}

int qtd_no(def_lista Lista, int nro){
    def_lista aux;
    int cont;
    for ( aux = Lista; aux != NULL; aux = aux->prox)
    {
        if (aux->info == nro)
        {
            cont++;
        }
        
    }
    return cont;
}