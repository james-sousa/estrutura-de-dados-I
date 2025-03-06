#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

int main(int argc, char const *argv[])
{
    Contatos **cont;
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
            printf("Quantos contatos: \n");
            scanf("%d",&qtd);
            cont = atribuir(cont,qtd);
            break;
        case 2:
            cont = adcionar(cont,qtd);
            
            break;
        case 3:
            imprimir(cont,qtd);
            break;
        case 4:
            
            break;
        case 5:
           
            break;
        case 6:
           
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