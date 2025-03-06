#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int **mat;
    int i,j,l,c,valor = 0;

    printf("Digite a quantidade de linhas da matriz: ");
    scanf("%d",&l);
    printf("Digite a quantidade de colunas: ");
    scanf("%d",&c);
    if (l < 1 || c < 1)
    {
        printf("Parametros invalidos");
        exit(1);
    }

    mat = (int **)malloc(l * sizeof(int));
    if (mat == NULL)
    {
        printf("Memoria insuficiente");
        exit(1);
    }

    for ( i = 0; i < l; i++)
    {
        mat[i] = (int *)malloc(c * sizeof(int));
        if (mat[i] == NULL)
        {
            printf("Memoria insuficiente");
            exit(1);
        }
        
    }

    for ( i = 0; i < l; i++)
    {
        for ( j = 0; j < c; j++)
        {
        
            mat[i][j] = valor += 1;
        }
        
    }
    printf("\n");

    for ( i = 0; i < l; i++)
    {
        for ( j = 0; j < c; j++)
        {
            printf("Numero %d linha %d coluna: %d",i+1,j+1,mat[i][j]);
            printf("\n");
            
        }
        
    }
    
    for ( i = 0; i < l; i++)
    {
        free(mat[i]);
        printf("linhas liberadas\n");
    }
    free(mat);
    printf("memoria liberada\n");
    
    
    
    
    return 0;
}
