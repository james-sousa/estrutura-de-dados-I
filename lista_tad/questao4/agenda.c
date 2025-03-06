#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

struct _etiqueta{
    char** etiquetas;
    int quant;
};
struct _contato{
    char nome[80];
    int numero;
    struct _etiqueta Et;
};
Contatos** atribuir(Contatos** cont,int qtd){
    int i,j,l,m,qte;
    cont = (Contatos **)malloc(qtd * sizeof(Contatos));
    if (cont == NULL)
    {
        printf("Memoria insuficiente!");
    }
    for ( i = 0; i < qtd; i++)
    {
        cont[i] = (Contatos *)malloc(sizeof(Contatos));
        printf("Digite o nome: \n");
        scanf("%s",&cont[i]->nome);
        printf("Digite o numero: \n");
        scanf("%d",&cont[i]->numero);
        printf("Quantas etiquetas para esse contato: \n");
        scanf("%d",&qte);
        cont[i]->Et.etiquetas = (char **)malloc(qte *sizeof(char));
        for ( j = 0; j < qte; j++)
        {
            cont[i]->Et.etiquetas[j] = (char *)malloc(sizeof(char));
            printf("Digite a %d etiqueta: \n",j+1);
            scanf("%s",cont[i]->Et.etiquetas[j]);

        }
        cont[i]->Et.quant += qte;
        
    }
    
    return cont;
    
}
void imprimir(Contatos** cont, int qtd){
    int i,j;

    for ( i = 0; i < qtd; i++)
    {
        printf("Nome: %s\n",cont[i]->nome);
        printf("Numero: %d\n",cont[i]->numero);
        for ( j = 0; j < cont[i]->Et.quant; j++)
        {
            printf("Etiquetas: %s\n",cont[i]->Et.etiquetas[j]);
        }
        
    }
    
}
Contatos** adcionar(Contatos** cont, int qtd){
    int i,j,igual,nqte;
    char nome[80];

    printf("Digite o nome: \n");
    scanf("%s",nome);
    for ( i = 0; i < qtd; i++)
    {
        igual = strcmp(cont[i]->nome,nome);
        if (igual == 0)
        {
            printf("Quantas etiquetas deseja adcionar: \n");
            scanf("%d",&nqte);
            cont[i]->Et.quant += nqte;
            cont[i]->Et.etiquetas = realloc(cont[i]->Et.etiquetas,cont[i]->Et.quant * sizeof(char));
            for ( j = cont[i]->Et.quant - nqte; j < cont[i]->Et.quant; j++)
            {
                printf("Digite a %d etiqueta: \n",j+1);
                cont[i]->Et.etiquetas[j] = (char *)malloc(100);
                scanf("%s",cont[i]->Et.etiquetas[j]);
            }
            
        }
        
        if (igual != 0)
        {
            printf("Contato não encpntrado!\n");
        }
        
        
    }
    return cont;
}
void buscar(Contatos** cont, int qtd){
    int encontrou = 0;
    char etiqueta[80];
    printf("Contatos com a etiqueta :\n");
    scanf("%s",etiqueta);
    for (int i = 0; i < qtd; i++) {
        for (int j = 0; j < cont[i]->Et.quant; j++) {
            if (strcmp(cont[i]->Et.etiquetas[j], etiqueta) == 0) {
                encontrou = 1;
                printf("Nome: %s\n", cont[i]->nome);
                printf("Numero: %d\n", cont[i]->numero);
                printf("Etiquetas: ");
                for (int k = 0; k < cont[i]->Et.quant; k++) {
                    printf("%s ", cont[i]->Et.etiquetas[k]);
                }
                printf("\n\n");
                break;  // Se a etiqueta é encontrada em um contato, passa para o próximo contato
            }
        }
    }

    if (!encontrou) {
        printf("Nenhum contato encontrado com a etiqueta \"%s\"\n", etiqueta);
    }
}
Contatos** remover(Contatos** cont, int qtd){
    int i, j;
    int encontrado = 0;
    char nome[80];
    printf("Digite o nome: \n");
    scanf("%s",nome);

    for (i = 0; i < qtd; i++) {
        if (strcmp(cont[i]->nome, nome) == 0) {
            encontrado = 1;

            // Libera a memória alocada para as etiquetas
            for (j = 0; j < cont[i]->Et.quant; j++) {
                free(cont[i]->Et.etiquetas[j]);
            }
            free(cont[i]->Et.etiquetas);

            // Libera a memória alocada para o contato
            free(cont[i]);

            // Remove o contato da lista
            for (int k = i; k < (qtd) - 1; k++) {
                cont[k] = cont[k + 1];
            }

            (qtd)--;
            cont = realloc(cont, (qtd) * sizeof(Contatos*));

            printf("Contato \"%s\" removido com sucesso!\n", nome);
            break;  // Termina o loop após encontrar o contato
        }
    }

    if (!encontrado) {
        printf("Contato \"%s\" não encontrado.\n", nome);
    }

    return cont;
}
void listar(Contatos** cont, int qtd){
    printf("Lista de Contatos:\n");
    for (int i = 0; i < qtd; i++) {
        printf("Nome: %s, Número: %d, Etiquetas: ", cont[i]->nome, cont[i]->numero);
        for (int j = 0; j < cont[i]->Et.quant; j++) {
            printf("%s ", cont[i]->Et.etiquetas[j]);
        }
        printf("\n");
    }
    printf("\n");
}
void atualizar(Contatos** cont, int qtd){
    int encontrado = 0,novoNumero;
    char nome[80];
    printf("Nome: \n");
    scanf("%s",nome);
    
    for (int i = 0; i < qtd; i++) {
        if (strcmp(cont[i]->nome, nome) == 0) {
            printf("Digite o novo numero: \n");
            scanf("%d",&novoNumero);
            cont[i]->numero = novoNumero;
            encontrado = 1;
            printf("Número de telefone para o contato \"%s\" atualizado para %d\n", nome, novoNumero);
            break;
        }
    }

    if (!encontrado) {
        printf("Contato \"%s\" não encontrado.\n", nome);
    }
}

void liberar(Contatos** cont, int qtd){
    for (int i = 0; i < qtd; i++) {
        // Libera a memória alocada para as etiquetas
        for (int j = 0; j < cont[i]->Et.quant; j++) {
            free(cont[i]->Et.etiquetas[j]);
        }
        free(cont[i]->Et.etiquetas);

        // Libera a memória alocada para o contato
        free(cont[i]);
    }
    free(cont);
}
