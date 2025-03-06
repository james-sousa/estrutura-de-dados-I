#include <stdio.h>
#include <stdlib.h>

typedef struct _jogador JogadorFutebol;

JogadorFutebol **atribui(int qtd);

void imprime(JogadorFutebol** jog, int qtd);

void soma(JogadorFutebol** jog, int qtd);

void Ehbom(JogadorFutebol** jog,int qtd);

void libera(JogadorFutebol **jog, int qtd);
