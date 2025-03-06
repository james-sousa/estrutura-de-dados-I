#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"
#include <string.h>

struct _jogador
{
    char nome[50];
    int jogos;
    int gols;
    int assistencias;
};

JogadorFutebol **atribui(int qtd){
    JogadorFutebol **jog;
    jog = (JogadorFutebol **)malloc(qtd * sizeof(JogadorFutebol));
    
    for (int i = 0; i < qtd; i++)
    {
        
        jog[i] = (JogadorFutebol *)malloc(sizeof(JogadorFutebol));

        printf("Digite o nome: \n");
        scanf("%s",jog[i]->nome);
        printf("Jogos: \n");
        scanf("%d",&jog[i]->jogos);
        printf("Gols: \n");
        scanf("%d",&jog[i]->gols);
        printf("Assistencias: \n");
        scanf("%d",&jog[i]->assistencias);

    }

    return jog;
    
}

void imprime(JogadorFutebol** jog, int qtd){
    for (int i = 0; i < qtd; i++)
    {
        printf("Nome: %s\n",jog[i]->nome);
        printf("Jogos: %d\n",jog[i]->jogos);
        printf("Gols: %d\n",jog[i]->gols);
        printf("Assistencias: %d\n",jog[i]->assistencias);
    }
    
}

void soma(JogadorFutebol** jog, int qtd) {
    char jogador1[60];
    char jogador2[60];
    int iguais1 = -1, iguais2 = -1;
    int i,j,gols = 0, assistencias = 0;

    if (qtd >= 2) {
        printf("Nome do jogador 1: \n");
        scanf(" %[^\n]s", jogador1);
        printf("Nome do jogador 2: \n");
        scanf(" %[^\n]s", jogador2);

        // Buscar jogador 1
        for ( i = 0; i < qtd; i++) {
            iguais1 = strcmp(jog[i]->nome, jogador1);
            if (iguais1 == 0) {
                break; // Parar a busca se encontrar o jogador 1
            }
        }

        // Buscar jogador 2
        for ( j = 0; j < qtd; j++) {
            iguais2 = strcmp(jog[j]->nome, jogador2);
            if (iguais2 == 0) {
                break; // Parar a busca se encontrar o jogador 2
            }
        }

        // Verificar se ambos os jogadores foram encontrados
        if (iguais1 == 0 && iguais2 == 0) {
            gols = jog[i]->gols + jog[j]->gols;
            assistencias = jog[i]->assistencias + jog[j]->assistencias;
        } else {
            printf("Pelo menos um dos jogadores não foi encontrado.\n");
            return; // Encerrar a função se um dos jogadores não foi encontrado
        }

    } else {
        printf("Quantidade de jogadores insuficiente!\n");
        return; // Encerrar a função se a quantidade de jogadores for insuficiente
    }

    printf("Soma dos gols: %d\n", gols);
    printf("Soma das assistencias: %d\n", assistencias);
}
void Ehbom(JogadorFutebol** jog,int qtd){
    int gols = 10;
    int iguais;
    char nome[60];
    printf("Digite o nome: ");
    scanf("%s",nome);
    for (int i = 0; i < qtd; i++)
    {
        iguais = strcmp(jog[i]->nome,nome);
        if (iguais == 0)
        {
            if (jog[i]->gols >= gols)
            {
                printf("O jogador eh bom!\n");
            }else
            {
                printf("O jogador eh ruim!\n");
            }
            
            
        }
        
        
        
        
        
    }

}

void libera(JogadorFutebol** jog, int qtd){
    for (int i = 0; i < qtd; i++)
    {
        free(jog[i]);
        printf("Memoria do laço liberada!\n");
    }
    free(jog);
    printf("Memoria liberada");
}