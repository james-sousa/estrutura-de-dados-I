#include <stdio.h>
#include <stdlib.h>
#include "livros.h"

int main(int argc, char const *argv[])
{
    Livro* liv;
    int qtd,escolha;
    while (1)
    {
        printf("Menu\n");
        printf("1-Atribuir\n2-Adcionar palavra chave\n3-Listar\n4-Busca palavra\n5-Remover\n6-Liberar\n7-Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d",&escolha);
        
        switch (escolha)
        {
        case 1:
            liv = atribuir(liv);
            break;
        case 2:
            adcionar(liv);
            
            break;
        case 3:
            imprimir(liv);
            break;
        case 4:
            buscar(liv);
            break;
        case 5:
            remover(liv);
            break;
        case 6:
            liberar(liv);
            break;
        case 7:
            printf("Saindo....\n");
            break;
        default:
            break;
        }
    }
    return 0;
}
