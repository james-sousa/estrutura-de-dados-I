#include <stdio.h>
#include <stdlib.h>

void func(int n, int a){
   
    if (a <= n)
    {
        printf("%d\n", a);
        func(n, a+2);
        
        

    }
    
}

int main(int argc, char const *argv[])
{
    int valor;
    int a = 0;
    printf("Digite um valor: ");
    scanf("%d",&valor);
    
    func(valor,a);
    return 0;
}

