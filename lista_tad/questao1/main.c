#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"

int main(int argc, char const *argv[])
{
    JogadorFutebol **jog;
    int qtd,op;
    char jogador[50];
    while (1)
    {

        printf("------Menu------");
        printf("\n1-atribuir\n2-listar\n3-Somar\n4-Jogador bom\n5-liberar\n6-Sair");
        printf("Digite sua escolha: ");
        scanf("%d",&op);

        switch (op)
        {
            case 1:
                printf("Quantos jopgadores: ");
                scanf("%d",&qtd);
                jog = atribui(qtd);
                break;
            
            case 2:
                imprime(jog,qtd);
                break;
            case 3:
                printf("Soma das estatisticas!\n");
                soma(jog,qtd);
                break;
            case 4:
                Ehbom(jog,qtd);
                break;
            case 5:
                libera(jog,qtd);
            case 6:
                break;
            default:
                break;
        }
    }
    
    

    return 0;
}
