#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.c"

int main(int argc, char const *argv[])
{
   Livro *lista = NULL;

    lista = insere_livro(lista,"alma","Edir macedo",2019,1);
    lista = insere_livro(lista,"1984","George orwel",1945,2);
    lista = insere_livro(lista,"sapiens","Yuval noah harari",2016,3);

    imprimir(lista);


    return 0;
}
