#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

int main(int argc, char const *argv[])
{
    No *lista = NULL;
    printf("Inserindo elementos no inicio!\n");
    lista = Insere_inicio(lista,10);
    lista = Insere_inicio(lista,5);
    lista = Insere_inicio(lista,5);
    imprimir(lista);
    printf("Inserindo elementos no final!\n");
    lista = insere_final(lista, 4);
    lista = insere_final(lista, 5);
    imprimir(lista);
    printf("Verificando em quantos nós tem o mesmo elemento!\n");
    int n = 5, res;
    res = qtd_no(lista,5);
    printf("O numero aparece em %d nó(s)\n",res);
    return 0;
}
