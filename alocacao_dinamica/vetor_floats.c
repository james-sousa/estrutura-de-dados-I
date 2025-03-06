#include <stdio.h>
#include <stdlib.h>

float Aloca_vetor(int n){
    float *v;
    v = (float *)malloc(n * sizeof(float));
    if (v == NULL)
    {
        printf("Memoria Insuficiente");
        return 0;
    }
    float numeros;

    for (int i = 0; i < n; i++)
    {
        printf("Numero: ");
        scanf("%f",&v[i]);
    }

    for (int i = n; i > 0; i--)
    {
        printf("Numeros: %.2f\n",v[i-1]);
    }

    free(v);
    return 0;
    
    
    
}




int main(int argc, char const *argv[])
{
    int n;

    printf("Digite o tamanho a ser alocado: ");
    scanf("%d", &n);
    Aloca_vetor(n);
    return 0;
}
