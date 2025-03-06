#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livros.h"

struct lista_palavras{
    char** palavras_pass;
    int quantidade;
};

struct _livro
{
    char titulo[60];
    char autor[80];
    int ano;
    struct lista_palavras pl;
};

Livro* atribuir(Livro* liv){
    int i,j;

    liv = (Livro*)malloc(sizeof(Livro));
    printf("Titulo: \n");
    scanf("%s",liv->titulo);
    printf("Autor: \n");
    scanf("%s",liv->autor);
    printf("Ano: \n");
    scanf("%d",&liv->ano);
    printf("Quantas palavras chaves deseja cadastrar no livro: %s\n",liv->titulo);
    scanf("%d",&liv->pl.quantidade);
    liv->pl.palavras_pass = (char **)malloc(liv->pl.quantidade * sizeof(char));
    for ( i = 0; i < liv->pl.quantidade; i++)
    {
        liv->pl.palavras_pass[i] = (char *)malloc(sizeof(char));
        printf("Digite a %d palavra: \n",i+1);
        scanf("%s",liv->pl.palavras_pass[i]);
    }
        
    return liv;

}

Livro* adcionar(Livro* liv){
    int qtpl,i;
    

    printf("Quantas palavras deseja adicionar ao livro %s: \n",liv->titulo);
    scanf("%d",&qtpl);
    liv->pl.quantidade += qtpl;
    liv->pl.palavras_pass = realloc(liv->pl.palavras_pass, liv->pl.quantidade * sizeof(char));
    for ( i = liv->pl.quantidade - qtpl; i < liv->pl.quantidade; ++i) {
        printf("Digite a palavra-chave %d: ", i + 1);
        liv->pl.palavras_pass[i] = malloc(100);  // Ajuste o tamanho conforme necessário
        scanf("%s", liv->pl.palavras_pass[i]);

    }
    return liv;

}

void imprimir(Livro* liv){
    printf("Titulo: %s\n",liv->titulo);
    printf("Autor: %s\n",liv->autor);
    printf("Ano: %d\n",liv->ano);
    printf("Palavras-chave: ");
    for (int i = 0; i < liv->pl.quantidade; i++)
    {
        printf("%s\n",liv->pl.palavras_pass[i]);
    }
    printf("\n");
}

void buscar(Livro* liv){
    int igual;
    char palavra[80];

    printf("Digite a palavra: \n");
    scanf("%s",palavra);
    for (int i = 0; i < liv->pl.quantidade; i++)
    {
        igual = strcmp(liv->pl.palavras_pass[i], palavra);
        if (igual == 0)
        {
            printf("A palavra esta na lista!\n");
            break;
        }else
        {
            printf("A palavra não esta na lista!\n");
            break;
        }
        
        
    }
    
}

void remover(Livro* liv) {
    int igual;
    char palavra[80];

    printf("Digite a palavra: \n");
    scanf("%s", palavra);

    int encontrou = 0;  // Variável para indicar se a palavra foi encontrada

    for (int i = 0; i < liv->pl.quantidade; i++) {
        igual = strcmp(liv->pl.palavras_pass[i], palavra);
        if (igual == 0) {
            free(liv->pl.palavras_pass[i]);
            for (int j = i; j < liv->pl.quantidade; j++)
            {
                liv->pl.palavras_pass[j] = liv->pl.palavras_pass[j + 1];
            }
            
            liv->pl.palavras_pass[liv->pl.quantidade - 1] = NULL;
            liv->pl.quantidade--;
            encontrou = 1;  // Indica que a palavra foi encontrada
            break;
        }
    }

    if (!encontrou) {
        printf("Palavra não encontrada!\n");
    }
}

void liberar(Livro* liv) {
    // Libera a memória alocada para cada palavra-chave
    for (int i = 0; i < liv->pl.quantidade; i++) {
        free(liv->pl.palavras_pass[i]);
    }
    free(liv);
    
}

