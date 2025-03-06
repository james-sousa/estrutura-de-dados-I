#include <stdio.h>
struct lista_palavras;
typedef struct _livro Livro;

Livro* atribuir(Livro* liv);
void imprimir(Livro* liv);
Livro* adcionar(Livro* liv);
void buscar(Livro* liv);
void liberar(Livro* liv);
void autor(Livro* liv);
void remover(Livro* liv);