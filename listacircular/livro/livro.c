#include <stdio.h>
#include <stdlib.h>
#include "livro.h"

Livro *criar(){
    Livro *novo_livro = (Livro *)malloc(sizeof(Livro));
}


Livro *insere_livro_circular(Livro *lista,const char *titulo,const char *autor, int ano, int id){
    Livro *novo_livro = criar();
    strcpy(novo_livro->titulo, titulo);
    strcpy(novo_livro->autor, autor);
    novo_livro->ano = ano;
    novo_livro->id = id;
    if (lista == NULL)
    {
        lista = novo_livro;
        novo_livro->prox = novo_livro;
    }else
    {
        novo_livro->prox = lista->prox;
        lista->prox = novo_livro;
    }
    
    return lista;
    
}

void imprimir(Livro *lista){
    if (lista == NULL)
    {
        printf("Lista vazia\n");
        return;
    }
    Livro *inicio = lista;
    do
    {
        printf("Id: %d, Titulo: %s, Autor: %s, Ano: %d\n",lista->id,lista->titulo,lista->autor,lista->ano);
        lista = lista->prox;
    } while (lista != inicio);
    
}