#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *v;
    int n,i,numero,soma=0;
    float media;

    printf("Digite a quantidade de elementos: ");
    scanf("%d",&n);
    v = (int *)malloc(n * sizeof(int));
    if (v == NULL){
        printf("Memoria insuficiente");
        return 0;
    }
    for ( i = 0; i < n; i++)
    {
        printf("Numero: ");
        scanf("%d", &v[i]);
        soma += v[i];
    }
    
    media = (float) soma / n;
    printf("Media: %.2f\n", media);
    free(v);
    return 0;
}
