#include <stdio.h>
#include <stdlib.h>
#include "aluno.c"

int main(int argc, char const *argv[])
{
   al *lista = NULL;

    lista = insere_aluno(lista,"james",12345,7.8,8.9,6.7);
    lista = insere_aluno(lista,"maria",2323,6.6,7.8,8.9);
    lista = insere_aluno(lista,"geovani",2022,7.8,9.0,7.8);

    imprimir(lista);


    return 0;
}
