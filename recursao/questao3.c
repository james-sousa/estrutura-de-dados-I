#include <stdio.h>
#include <stdlib.h>

int fatorial(int n){
    if (n <= 1)
    {
        return 1;
    }
    return n*(fatorial(n-1));
    
}

int main(int argc, char const *argv[])
{
    int n,result;
    printf("Valor: ");
    scanf("%d",&n);
    result = fatorial(n);
    printf("Resultado: %d\n",result);
    return 0;
}
