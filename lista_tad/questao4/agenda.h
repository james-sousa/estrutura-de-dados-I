#include <stdio.h>

typedef struct _contato Contatos;
struct _etiqueta;

Contatos** atribuir(Contatos** cont,int qtd);
void imprimir(Contatos** cont, int qtd);
Contatos** adcionar(Contatos** cont, int qtd);
void buscar(Contatos** cont, int qtd);
Contatos** remover(Contatos** cont, int qtd);
void listar(Contatos** cont, int qtd);
void atualizar(Contatos** cont, int qtd);
void liberar(Contatos** cont, int qtd);
