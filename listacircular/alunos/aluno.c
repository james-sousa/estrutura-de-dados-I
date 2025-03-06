#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include <string.h>


al *criar(){
    al *aluno_novo = (al *)malloc(sizeof(al));
    return aluno_novo;
}
al *insere_aluno(al *lista, const char *nome, int mat, float nota1,float nota2,float nota3){
    al *aluno = criar();
    aluno->matricula = mat;
    strcpy(aluno->nome,nome);
    aluno->nota1 = nota1;
    aluno->nota2 = nota2;
    aluno->nota3 = nota3;
    if (lista == NULL)
    {
        lista = aluno;
        aluno->prox = lista;
    }else
    {
        aluno->prox = (lista)->prox;
        (lista)->prox = aluno;
    }
    
    return lista;
}

void imprimir(al *lista){
    al *aux;
    aux = lista->prox;

    do
    {
        printf("Nome: %s\n",aux->nome);
        printf("Matricula: %d\n",aux->matricula);
        printf("Nota1: %.2f\n",aux->nota1);
        printf("Nota2: %.2f\n",aux->nota2);
        printf("Nota3: %.2f\n",aux->nota3);
        aux = aux->prox;
    } while (aux != lista->prox);
    
    printf("\n");
}