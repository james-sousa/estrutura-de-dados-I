#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *v;
    int numero;
    int tamanho = 5;

    v = (int*)malloc(tamanho * sizeof(int));
    for ( int i = 0; i < tamanho; i++)
    {
        scanf("%d",&numero);
        v[tamanho - 1] = numero;
    }

    for (int i = 0; i < tamanho; i++)
    {
        printf("%d", &v[i]);
    }
    
    return 0;
}
