#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.c"

int main(int argc, char const *argv[])
{
   Livro *lista = NULL;

    
    lista = insere_livro_circular(lista,"1984","George orwel",1945,2);
    lista = insere_livro_circular(lista,"sapiens","Yuval noah harari",2016,3);
    lista = insere_livro_circular(lista,"pequeno principe","ll",2015,5);
    lista = insere_livro_circular(lista,"livre","nn",2000,6);
    lista = insere_livro_circular(lista,"alma","Edir macedo",2019,1);
    imprimir(lista);


    return 0;
}