#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char vetor[] = "James Sousa";
    char palavra;
    int tamanho = 256;
    int *ocorrencias = (int *)malloc(tamanho * sizeof(int));
    
    if (ocorrencias == NULL)
    {
        printf("Erro na alocação\n");
        return 1;
    }
    
    for (int i = 0; vetor[i] != '\0'; i++)
    {
        
        
        char caractere = vetor[i];
        ocorrencias[(int)caractere]++;
        
        
    }
    for (int i = 0; i < tamanho; i++)
    {
        if (ocorrencias[i] > 0)
        {
            printf("'%c' = %d\n",(char)i,ocorrencias[i]);
        }
        
        
    }
    
    free(ocorrencias);
    return 0;
}
