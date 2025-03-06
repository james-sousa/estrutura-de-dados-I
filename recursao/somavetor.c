#include <stdio.h>
#include <stdlib.h>

int somalinear(int vet[],int n){
    if (n == 0)
    {
        return 0;
    }else
    {
        return somalinear(vet, n-1) + vet[n-1];
    }
    return 0;
    
}

int main(int argc, char const *argv[])
{
    int vet[10];
    int n,i,soma;
    printf("Digite os valores!\n");
    for ( i = 0; i < 10; i++)
    {
        printf("Numero: ");
        scanf("%d",&vet[i]);
    }
    printf("Digite o valor de n: ");
    scanf("%d",&n);
    soma = somalinear(vet,n);
    printf("A soma eh: %d",soma);
    
    return 0;
}
