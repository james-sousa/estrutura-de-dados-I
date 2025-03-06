#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int soma,numero,menor,maior,tam=0;
    float media;
    int *vet = NULL;
    soma = 0;

    while (1)
    {
        printf("Digite um numero: ");
        scanf("%d", &numero);

        if (numero == -1)
        {
            break;
        }

        tam++;
        vet = (int *)malloc(tam * sizeof(int));
        
        if (vet == NULL){
            printf("Erro na alocação");
            exit(1);
        }

        vet[tam - 1] = numero;
        soma += numero;
        if (tam == 1 || numero < menor)
        {
            menor = numero;
        }
        if (tam == 1 || numero > maior)
        {
            maior = numero;
        }

        
        
        
        
        
    }
    if (tam == 0)
        {
            printf("Nenhum numero foi inserido\n");
        }else
        {
            media = (float)soma/ tam;
            printf("Soma: %d\n", soma);
            printf("Media: %.2f\n", media);
            printf("Menor: %d\n", menor);
            printf("Maior: %d\n", maior);
            
        }

    free(vet);
    return 0;
}
