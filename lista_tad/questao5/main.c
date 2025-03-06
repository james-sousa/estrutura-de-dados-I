#include <stdio.h>
#include <stdlib.h>
#include "projeto.h"

int main() {
    // Exemplo de utilização
    pjt* projeto1 = (pjt *)malloc(sizeof(pjt));
    atribuir(projeto1, "Projeto 1", "01/01/2023", "31/12/2023");
    adicionarTarefa(projeto1, "Implementar funcionalidade X", "Em andamento");
    adicionarMembroEquipe(projeto1, "João");
    adicionarMembroEquipe(projeto1, "Maria");

    imprimir(projeto1);

    // Teste de remover tarefa
    removerTarefa(projeto1, "Implementar funcionalidade X");
    imprimir(projeto1);

    // Teste de concluir tarefa
    adicionarTarefa(projeto1, "Testar funcionalidade X", "Em andamento");
    concluirTarefa(projeto1, "Testar funcionalidade X");
    imprimir(projeto1);

    // Teste de listar projetos por membro da equipe
    pjt* projeto2 = (pjt *)malloc(sizeof(pjt));
    atribuir(projeto2, "Projeto 2", "01/02/2023", "30/11/2023");
    adicionarMembroEquipe(projeto2, "Maria");
    adicionarMembroEquipe(projeto2, "Carlos");

    pjt* projetos[] = { projeto1, projeto2 };

    listarProjetosPorMembro(projetos, 2, "Maria");

    // Liberar memória
    liberarMemoria(projeto1);
    liberarMemoria(projeto2);

    return 0;
}