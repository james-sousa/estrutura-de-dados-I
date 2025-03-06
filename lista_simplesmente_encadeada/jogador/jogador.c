#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogador.h"

jog *criar(){
    jog *novo_jo = (jog *)malloc(sizeof(jog));
    return novo_jo;
}

jog *insere_jogador(jog *lista,int gols,int jogos,const char *nome, int assist){
    jog *novo_jog = criar();
    novo_jog->gols = gols;
    novo_jog->jogos = jogos;
    strcpy(novo_jog->nome,nome);
    novo_jog->asst = assist;

    if (lista == NULL)
    {
        lista = novo_jog;
        novo_jog->prox = NULL;
    }else
    {
        novo_jog->prox = lista;
        lista = novo_jog;
    }
    printf("Jogador inserido com sucesso!\n");

    return lista;

}

void imprime(jog *lista){
    jog *aux = lista;
    while (aux != NULL)
    {
        printf("Nome: %s\n",aux->nome);
        printf("jogos: %d\n",aux->jogos);
        printf("gols: %d\n",aux->gols);
        printf("Assistencias: %d\n",aux->asst);
        printf("\n");
        aux = aux->prox;
    }
    
}