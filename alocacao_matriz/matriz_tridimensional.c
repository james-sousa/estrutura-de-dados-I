#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int ***cubo;
    int d1,d2,d3,i,j;

    if (d1 < 1 || d2 < 1 || d3 < 1)
    {
        printf("Parametro invalido");
        exit(1);
    }
    cubo = (int***)malloc(d1 * sizeof(int **));
    for ( i = 0; i < d1; i++)
    {
        cubo[i] = (int **)malloc(d2 * sizeof(int *));
        for ( j = 0; j < d2; j++)
        {
            cubo[i][j] = (int *)malloc(d3 * sizeof(int));
        }
        
    }
    
    

    return 0;
}
