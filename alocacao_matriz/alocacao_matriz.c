#include <stdio.h>
#include <stdlib.h>

int **Alocar_matriz(int m, int n){
    int **v;
    int i;
    if (m < 1 || n < 1)
    {
        printf("Valor invalido");
        return (NULL);
    }

    v = (int **)malloc(m * sizeof(int *));
    if (v == NULL)
    {
        printf("Memoria insuficiente");
        return (NULL);
    }

    for ( i = 0; i < m; i++)
    {
        v[i] = (int *)malloc(n * sizeof(int));
        if (v[i] == NULL)
        {
            printf("Memoria insuficiente");
            return (NULL);
        }
        
    }
    
    return (v);
    
}

int **Liberar_matriz(int m, int n, int **v){
    int i;
    if (v == NULL)
    {
        return (NULL);
    }
    if (m < 1 || n < 1)
    {
        printf("Paramentro invalido");
        return (v);
    }
    for ( i = 0; i < m; i++)
    {
        free(v[i]);
    }
    free(v);

    return (NULL);
    
    
}

int main(int argc, char const *argv[])
{
    int **mat;
    int l,c;
    int i,j,numero;

    printf("Digite a quantidade de linhas da matriz: ");
    scanf("%d",&l);
    printf("Digite a quantidade de colunas da matriz: ");
    scanf("%d",&c);

    mat = Alocar_matriz(l,c);

    for ( i = 0; i < l; i++)
    {
        for ( j = 0; j < c; j++)
        {
            printf("Digite um numero da %d linha %d coluna: ", i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
        
    }
    for ( i = 0; i < l; i++)
    {
        for ( j = 0; j < c; j++)
        {
            printf("Numero da %d linha %d coluna: %d",i+1,j+1,mat[i][j]);
            printf("\n");
        }
        
    }
    
    mat = Liberar_matriz(l,c,mat);
    printf("Memoria liberada\n");
    



    return 0;
}
