#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *v;
    int i,n,numeros;

    printf("Digite o tamanho: ");
    scanf("%d",&n);

    v = (int *)malloc(n * sizeof(int));
    if (v == NULL)
    {
        printf("Memoria Insuficiente");
        return 0;
    }

    for ( i = 0; i < n; i++)
    {
        printf("Digite um numero: ");
        scanf("%d",&v[i]);
    }

    for ( i = n; i > 0; i--)
    {
        printf("Numero: %d\n",v[i-1]);
    }
    
    free(v);
    
    
    return 0;
}
