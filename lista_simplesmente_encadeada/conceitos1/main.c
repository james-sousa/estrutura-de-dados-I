#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

int main() {
    // Initializing an empty list
    def_lista minha_lista = inicializa();

    // Inserting elements at the beginning
    insere_inicio(&minha_lista, 3);
    insere_inicio(&minha_lista, 7);
    insere_inicio(&minha_lista, 12);

    // Printing the list
    imprime_lista(minha_lista);

    // Inserting elements at the end
    insere_final(&minha_lista, 20);
    insere_final(&minha_lista, 5);

    // Printing the updated list
    imprime_lista(minha_lista);

    // Searching for an element
    int elemento_busca = 7;
    if (busca(minha_lista, elemento_busca)) {
        printf("%d encontrado na lista.\n", elemento_busca);
    } else {
        printf("%d não encontrado na lista.\n", elemento_busca);
    }
    int num,qatd_no;
    printf("quantos nós tem o numero!\n");
    printf("Digite o numero: \n");
    qatd_no = qtd_no(minha_lista,num);

    printf("%d nó(s) tem esse elemento!\n");
    // Freeing the allocated memory
    def_lista aux;
    while (minha_lista != NULL) {
        aux = minha_lista;
        minha_lista = minha_lista->prox;
        free(aux);
    }

    return 0;
}
