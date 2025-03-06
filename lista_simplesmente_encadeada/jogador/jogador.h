#include <stdio.h>
#include <stdlib.h>

struct Jogador{
    int jogos;
    int gols;
    int asst;
    char nome[50];
    struct Jogador *prox;
};
typedef struct Jogador jog;

jog *criar();

jog *insere_jogador(jog *lista,int gols,int jogos,const char *nome, int assist);

void imprime(jog *lista);
