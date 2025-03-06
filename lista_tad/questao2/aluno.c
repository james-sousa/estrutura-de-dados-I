#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct _aluno
{
    char nome[100];
    int matricula;
    float nota1;
    float nota2;
    float nota3;
};

Aluno** atribuir(Aluno** al,int qtd){
    
    al =(Aluno**)malloc(qtd * sizeof(Aluno));
    if (al == NULL)
    {
        printf("Memoria insuficiente!");
        exit(1);
    }
    
    for (int i = 0; i < qtd; i++)
    {
        al[i] = (Aluno *)malloc(qtd * sizeof(Aluno));
        printf("Nome: \n");
        scanf("%s", al[i]->nome);
        printf("Matricula: \n");
        scanf("%d",&al[i]->matricula);
        printf("Digite a primeira nota: \n");
        scanf("%f",&al[i]->nota1);
        printf("Digite a segunda nota: \n");
        scanf("%f",&al[i]->nota2);
        printf("Digite a terceira nota: \n");
        scanf("%f",&al[i]->nota3);

    }

    return al;
    
    
}

void imprimir(Aluno** al, int qtd){
    for (int i = 0; i < qtd; i++)
    {
        printf("Nome: %s\n",al[i]->nome);
        printf("Matricula: %d\n",al[i]->matricula);
        printf("1 Nota: %.2f\n",al[i]->nota1);
        printf("2 Nota: %.2f\n",al[i]->nota2);
        printf("3 Nota: %.2f\n",al[i]->nota3);

    }
    printf("\n");
    
}

void media(Aluno** al, int qtd){
    float media;
    char nomeAluno[60];
    int igual;

    printf("Digite o nome: \n");
    scanf("%s",nomeAluno);

    for (int i = 0; i < qtd; i++)
    {
        igual = strcmp(al[i]->nome,nomeAluno);
        if (igual == 0)
        {
            media = (al[i]->nota1 + al[i]->nota2 + al[i]->nota3) / 3;
            printf("A media do aluno eh: %.2f\n", media);
        }else
        {
            printf("Aluno não encontrado\n");
        }
        
        
    }
    

}

void aprovacao(Aluno** al, int qtd){
    float media;
    char nomeAluno[60];
    int igual;

    printf("Digite o nome: \n");
    scanf("%s",nomeAluno);

    for (int i = 0; i < qtd; i++)
    {
        igual = strcmp(al[i]->nome,nomeAluno);
        if (igual == 0)
        {
            media = (al[i]->nota1 + al[i]->nota2 + al[i]->nota3) / 3;
            if (media >= 6.0)
            {
                printf("Aluno aprovado!\n");
                break;
            }else
            {
                printf("Aluno reprovado!\n");
                break;
            }
            
            
        }else
        {
            printf("Aluno não encontrado\n");
        }
        
        
    }
    

}

void liberar(Aluno** al, int qtd){
    for (int i = 0; i < qtd; i++)
    {
        free(al[i]);
        printf("Memoria interna liberada\n");
    }
    free(al);
    printf("Memoria externa liberada\n");
    
}


