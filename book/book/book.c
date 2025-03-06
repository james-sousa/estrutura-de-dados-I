#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

struct book{
    char titulo[100];
    char autor[50];
    int ano;
    int id;
    struct book* next;
};


// Função para inserir um novo livro na lista, mantendo a ordem pelo ID
void inserir_livro(ListaLivros* lista, const char* titulo, const char* autor, int ano, int id) {
    Book* novo_livro = (Book*)malloc(sizeof(Book));
    strcpy(novo_livro->titulo, titulo);
    strcpy(novo_livro->autor, autor);
    novo_livro->ano = ano;
    novo_livro->id = id;

    if (!lista->inicio || novo_livro->id < lista->inicio->id) {
        novo_livro->next = lista->inicio;
        lista->inicio = novo_livro;
    } else {
        Book* atual = lista->inicio;
        while (atual->next && atual->next->id < novo_livro->id) {
            atual = atual->next;
        }
        novo_livro->next = atual->next;
        atual->next = novo_livro;
    }
}

// Função para remover um livro com base no ID
void remover_livro(ListaLivros* lista, int id) {
    Book* atual = lista->inicio;
    if (atual && atual->id == id) {
        lista->inicio = atual->next;
        free(atual);
        return;
    }
    Book* anterior = NULL;
    while (atual && atual->id != id) {
        anterior = atual;
        atual = atual->next;
    }
    if (atual == NULL) {
        return;
    }
    anterior->next = atual->next;
    free(atual);
}

// Função para listar livros de um autor, ordenados por ano de publicação
ListaLivros listar_livros_por_autor(ListaLivros* lista, const char* autor) {
    ListaLivros lista_autor;
    lista_autor.inicio = NULL;

    Book* atual = lista->inicio;
    while (atual) {
        if (strcmp(atual->autor, autor) == 0) {
            inserir_livro(&lista_autor, atual->titulo, atual->autor, atual->ano, atual->id);
        }
        atual = atual->next;
    }
    return lista_autor;
}

// Função para atualizar o ano de publicação de um livro dado o ID
void atualizar_ano_publicacao(ListaLivros* lista, int id, int novo_ano) {
    Book* atual = lista->inicio;
    while (atual) {
        if (atual->id == id) {
            atual->ano = novo_ano;
            return;
        }
        atual = atual->next;
    }
}

// Função para imprimir a lista de livros
void imprimir_lista(ListaLivros* lista) {
    Book* atual = lista->inicio;
    while (atual) {
        printf("ID: %d, Título: %s, Autor: %s, Ano: %d\n", atual->id, atual->titulo, atual->autor, atual->ano);
        atual = atual->next;
    }
}



