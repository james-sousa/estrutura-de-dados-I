#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "criador.h"
#include "fazenda.h"
#include "fazenda.c"
#include "criador.c"
#include "animal.c"
#include "animal.h"
//---------------------------------------------------
void exibirMenu()
{
    printf("\n1 - Cadastrar criador");
    printf("\n2 - Remover criador");
    printf("\n3 - Mostrar criadores");
    printf("\n4 - Cadastrar fazenda");
    printf("\n5 - Mostrar Fazendas");
    printf("\n6 - Remover fazenda");
    printf("\n7 - Alterar fazenda");
    printf("\n8 - Cadastrar animal");
    printf("\n9 - Mostrar rebanho");
    printf("\n10 - Remover animal");
    printf("\n11 - Permutar animal");
    printf("\n12 - Numero de animais por sexo");
    printf("\n13 - Total de arrobas de uma fazenda");
    printf("\n14 - Valor Total da fazenda");
    printf("\n15 - Listar animais por status");
    printf("\n16 - EXIT\n");
}
//---------------------------------------------------
int main()
{
    int opcao, id, destino;
    Criador *criador, *criador2, *lista;
    Fazenda *fazenda;

    lista = criarListaDuplaCriadores();

    srand((unsigned)time(NULL));

    while (1)
    {
        exibirMenu();
        printf("\nInsira uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            lista = cadastrarCriador(lista);
            break;
        case 2:
            printf("\nInsira o id do criador: ");
            scanf("%d", &id);
            lista = removerCriador(lista, id);
            break;
        case 3:
            mostrarCriadores(lista);
            break;
        case 4:
            printf("\nInsira o id do criador: ");
            scanf("%d", &id);
            cadastrarFazendas(lista, id);
            break;
        case 5:
            printf("\nInsira o id do criador: ");
            scanf("%d", &id);
            criador = BuscarIdCriador(lista, id);
            criador ? mostrarTodasFazendas(criador) : printf("\nCriador inexistente!\n");
            break;
        case 6:
            printf("Insira o id do criador: ");
            scanf("%d", &id);
            criador = BuscarIdCriador(lista, id);
            criador ? removerFazendas(criador) : printf("\nCriador inexistente!\n");
            break;
        case 7:
            printf("Insira o id do criador: ");
            scanf("%d", &id);
            criador = BuscarIdCriador(lista, id);
            criador ? alterarFazendas(criador) : printf("\nCriador inexistente!\n");
            break;
        case 8:
            printf("\nInsira o ID do criador: ");
            scanf("%d", &id);
            criador = BuscarIdCriador(lista, id);
            criador ? cadastrarCriadorFazendaRebanho(criador) : printf("\nCriador inexistente!\n");
            break;
        case 9:
            printf("\nInsira o ID do criador: ");
            scanf("%d", &id);
            criador = BuscarIdCriador(lista, id);
            criador ? mostrarCriadorFazendaAnimais(criador) : printf("\nCriador inexistente!\n");
            break;
        case 10:
            printf("\nInsira o ID do criador: ");
            scanf("%d", &id);
            criador = BuscarIdCriador(lista, id);
            criador ? removerCriadorFazendaAnimal(criador) : printf("\nCriador inexistente!\n");
            break;
        case 11:
            printf("\nInsira o ID do criador de origem: ");
            scanf("%d", &id);
            printf("\nInsira o ID do criador de destino: ");
            scanf("%d", &destino);
            criador = BuscarIdCriador(lista, id);
            criador2 = BuscarIdCriador(lista, destino);
            (criador && criador2) ? permutarCriadorFazendaAnimal(criador, criador2) : printf("\nCriadores inexistentes!\n");
            break;
        case 12:
            printf("\nInsira o ID do criador: ");
            scanf("%d", &id);
            criador = BuscarIdCriador(lista, id);
            criador ? quantSexoCriadorAnimais(criador) : printf("\nCriador inexistente!\n");
            break;
        case 13:
            printf("\nInsira o ID do criador: ");
            scanf("%d", &id);
            criador = BuscarIdCriador(lista, id);
            criador ? arrobaTotal(criador->fazendas) : printf("\nCriador inexistente!\n");
            break;
        case 14:
            printf("\nInsira o ID do criador: ");
            scanf("%d", &id);
            criador = BuscarIdCriador(lista, id);
            criador ? printValorTotal(criador) : printf("\nCriador inexistente!\n");
            break;
        case 15:
            printf("\nInsira o ID do criador: ");
            scanf("%d", &id);
            criador = BuscarIdCriador(lista, id);
            criador ? printListaStatusAnimais(criador) : printf("\nCriador inexistente!\n");
            break;
        case 16:
            printf("\nSaindo...\n");
            liberarMemoria(lista);
            return 0;
        default:
            printf("\nInsira uma opcao valida!\n");
        }
    }
    return 0;
}
