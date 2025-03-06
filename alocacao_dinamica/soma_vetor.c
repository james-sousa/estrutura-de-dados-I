#include <stdio.h>
#include <stdlib.h>

int *soma_vetor(int *vetor1, int *vetor2, int tamanho){
    int *resultado = (int *)malloc(tamanho * sizeof(int));
    if (resultado == NULL)
    {
        printf("Memoria Insuficiente");
        exit(1);

    }

    for (int i = 0; i < tamanho; i++)
    {
        resultado[i] = vetor1[i] + vetor2[i];
    }
    
    return resultado;
    
}

int main(int argc, char const *argv[])
{
    int tamanho = 5;
    int *vetor1 = (int *)malloc(tamanho * sizeof(int));
    int *vetor2 = (int *)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++)
    {
        printf("Num :");
        scanf("%d",&vetor1[i]);
        printf("Num2: ");
        scanf("%d", &vetor2[i]);
    }

    int *resultado = soma_vetor(vetor1,vetor2,tamanho);
    printf("Vetor resultado");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d\n",resultado[i]);
    }
    printf("\n");
    free(vetor1);
    free(vetor2);
    free(resultado);
    
    return 0;
}
