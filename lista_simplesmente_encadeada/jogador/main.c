#include <stdio.h>
#include <stdlib.h>
#include "jogador.c"

int main(int argc, char const *argv[])
{
    jog *lista = NULL;
    lista = insere_jogador(lista,20,24,"Gabi",5);
    lista = insere_jogador(lista,19,25,"pedro",3);
    imprime(lista);
    return 0;
}
