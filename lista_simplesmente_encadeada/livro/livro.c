#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"

Livro *criar(){
    Livro *novo_livro = (Livro *)malloc(sizeof(Livro));
}
Livro *insere_livro(Livro *lista,const char *titulo,const char *autor, int ano, int id){
    Livro *novo_livro = criar();
    strcpy(novo_livro->titulo, titulo);
    strcpy(novo_livro->autor, autor);
    novo_livro->ano = ano;
    novo_livro->id = id;
    if (lista == NULL)
    {
        lista = novo_livro;
        novo_livro->prox = NULL;
    }else
    {
        novo_livro->prox = lista;
        lista = novo_livro;
    }
    
    return lista;
    
}
void imprimir(Livro *lista){
    Livro *aux = lista;
    while (aux != NULL)
    {
        printf("Id: %d, Titulo: %s, Autor: %s, Ano: %d\n",aux->id,aux->titulo,aux->autor,aux->ano);
        aux = aux->prox;
    }
    
}

