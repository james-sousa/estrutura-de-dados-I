#include <stdio.h>
#include <stdlib.h>

void trocar(char alfabeto[],int i, int j){
    char temp = alfabeto[i];
    alfabeto[i] = alfabeto[j];
    alfabeto[j] = temp;
}

void permutacao(char alfabeto[], int inicio, int tamanho){
    if (inicio == tamanho - 1)
    {
        printf("%s\n",alfabeto);
        return;
    }
    for (int i = 0; i < tamanho; i++)
    {
        trocar(alfabeto,inicio,i);
        permutacao(alfabeto,inicio + 1,tamanho);
        trocar(alfabeto,inicio,i);
    }
    
    
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Digite o valor de n: \n");
    scanf("%d",&n);

    if (n < 1 || n > 26)
    {
        printf("Digite um valor valido!\n");
        return 1;
    }
    
    char alfabeto[27];
    for (int i = 0; i < n; i++)
    {
        alfabeto[i] = 'a' + i;
    }
    alfabeto[n] = '\0';
    printf("Permutações das %d primeiras letras: \n",n);
    permutacao(alfabeto,0,n);
    return 0;
}
