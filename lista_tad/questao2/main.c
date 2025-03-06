#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main(int argc, char const *argv[])
{
    Aluno **al;
    int qtd,escolha;
    while (1)
    {
        printf("Menu\n");
        printf("1-Atribuir\n2-Listar\n3-Media\n4-Aprovacao\n5-liberar\n6-Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d",&escolha);
        
        switch (escolha)
        {
        case 1:
            printf("Digite a quantidade: \n");
            scanf("%d",&qtd);
            al = atribuir(al,qtd);
            break;
        case 2:
            imprimir(al,qtd);
            break;
        case 3:
            media(al,qtd);
            break;
        case 4:
            aprovacao(al,qtd);
            break;
        case 5:
            liberar(al,qtd);
            break;
        case 6:
            printf("Saindo....\n");
            break;
        default:
            break;
        }
    }
    
    
    return 0;
}
