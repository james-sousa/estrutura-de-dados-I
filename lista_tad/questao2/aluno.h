#include <stdio.h>

typedef struct _aluno Aluno;

Aluno** atribuir(Aluno** al,int qtd);
void imprimir(Aluno** al,int qtd);
void media(Aluno** al, int qtd);
void aprovacao(Aluno** al, int qtd);
void liberar(Aluno** al,int qtd);