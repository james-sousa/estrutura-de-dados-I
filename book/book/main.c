#include <stdio.h>
#include <stdlib.h>
#include "book.h"

int main() {
    ListaLivros lista;
    lista.inicio = NULL;

    // Inserir livros
    inserir_livro(&lista, "sapines", "yuval harari", 2016, 1);
    inserir_livro(&lista, "1984", "George orwel", 1940, 2);
    inserir_livro(&lista, "Alma", "Edir macedo", 2010, 3);

    printf("Lista de livros:\n");
    imprimir_lista(&lista);

    // Remover livro com ID 2
    remover_livro(&lista, 2);
    printf("\nLista de livros após a remoção do livro com ID 2:\n");
    imprimir_lista(&lista);

    // Listar livros do Autor1
    ListaLivros lista_autor1 = listar_livros_por_autor(&lista, "Edir macedo");
    printf("\nLista de livros do Autor1:\n");
    imprimir_lista(&lista_autor1);

    // Atualizar ano de publicação do livro com ID 3
    atualizar_ano_publicacao(&lista, 3, 2020);
    printf("\nLista de livros após a atualização do ano de publicação do livro com ID 3:\n");
    imprimir_lista(&lista);

    return 0;
}