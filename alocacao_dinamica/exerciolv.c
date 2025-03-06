#include <stdio.h>
#include <stdlib.h>
//programa que inverte os numeros digitados
int main(int argc, char const *argv[])
{
    int *v;
    int i,n;

    printf("Digite o tamanho: ");
    scanf("%d",&n);
    v = (int *)malloc(n * sizeof(int));

    for ( i = 0; i < n; i++)
    {
        scanf("%d",&v[i]);
    }    
    for ( i = n; i > 0; i--)
    {
        printf("posicao = %d valor = %d\n",i,v[i-1]);
    }

    free(v);
    
    return 0;
}
