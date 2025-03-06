#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projeto.h"

struct _tarefa {
    char descricao[100];
    char status[20]; // "Concluída" ou "Em andamento"
};

struct _membro {
    char nome[50];
};

struct projeto {
    char nome[100];
    char dataInicio[20];
    char dataConclusao[20];
    struct _tarefa* tarefas;
    int numTarefas;
    struct _membro* equipe;
    int numMembros;
};

void atribuir(pjt* projeto, const char* nome, const char* dataInicio, const char* dataConclusao) {
    strcpy(projeto->nome, nome);
    strcpy(projeto->dataInicio, dataInicio);
    strcpy(projeto->dataConclusao, dataConclusao);
    projeto->tarefas = NULL;
    projeto->numTarefas = 0;
    projeto->equipe = NULL;
    projeto->numMembros = 0;
};

void imprimir(pjt* projeto) {
    printf("Nome do Projeto: %s\n", projeto->nome);
    printf("Data de Início: %s\n", projeto->dataInicio);
    printf("Data de Conclusão: %s\n", projeto->dataConclusao);

    printf("Tarefas:\n");
    for (int i = 0; i < projeto->numTarefas; i++) {
        printf("- Descrição: %s, Status: %s\n", projeto->tarefas[i].descricao, projeto->tarefas[i].status);
    }

    printf("Membros da Equipe:\n");
    for (int i = 0; i < projeto->numMembros; i++) {
        printf("- %s\n", projeto->equipe[i].nome);
    }

    printf("\n");
};

void adicionarTarefa(pjt* projeto, const char* descricao, const char* status) {
    projeto->numTarefas++;
    projeto->tarefas = realloc(projeto->tarefas, projeto->numTarefas * sizeof(struct _tarefa));
    strcpy(projeto->tarefas[projeto->numTarefas - 1].descricao, descricao);
    strcpy(projeto->tarefas[projeto->numTarefas - 1].status, status);
};

void adicionarMembroEquipe(pjt* projeto, const char* nome) {
    projeto->numMembros++;
    projeto->equipe = realloc(projeto->equipe, projeto->numMembros * sizeof(struct _membro));
    strcpy(projeto->equipe[projeto->numMembros - 1].nome, nome);
};

void removerTarefa(pjt* projeto, const char* descricao) {
    for (int i = 0; i < projeto->numTarefas; i++) {
        if (strcmp(projeto->tarefas[i].descricao, descricao) == 0) {
            // Desloca as tarefas para preencher o espaço da tarefa removida
            for (int j = i; j < projeto->numTarefas - 1; j++) {
                projeto->tarefas[j] = projeto->tarefas[j + 1];
            }
            projeto->numTarefas--;
            projeto->tarefas = realloc(projeto->tarefas, projeto->numTarefas * sizeof(struct _tarefa));
            printf("Tarefa \"%s\" removida com sucesso!\n", descricao);
            return;
        }
    }
    printf("Tarefa \"%s\" não encontrada.\n", descricao);
};

void concluirTarefa(pjt* projeto, const char* descricao) {
    for (int i = 0; i < projeto->numTarefas; i++) {
        if (strcmp(projeto->tarefas[i].descricao, descricao) == 0) {
            strcpy(projeto->tarefas[i].status, "Concluída");
            printf("Tarefa \"%s\" marcada como concluída.\n", descricao);
            return;
        }
    }
    printf("Tarefa \"%s\" não encontrada.\n", descricao);
};

// Função para listar projetos por membro da equipe
void listarProjetosPorMembro(pjt** projetos, int numProjetos, const char* membro) {
    printf("Projetos do Membro \"%s\":\n", membro);

    for (int i = 0; i < numProjetos; i++) {
        for (int j = 0; j < projetos[i]->numMembros; j++) {
            if (strcmp(projetos[i]->equipe[j].nome, membro) == 0) {
                printf("- %s\n", projetos[i]->nome);
                break;
            }
        }
    }

    printf("\n");
}

// Função para liberar a memória alocada para o projeto, incluindo tarefas e membros da equipe
void liberarMemoria(pjt* projeto) {
    free(projeto->tarefas);
    free(projeto->equipe);
    free(projeto);
};



