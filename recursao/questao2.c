#include <stdio.h>
#include <stdlib.h>

int soma(int n, int a){
    int som = 0;
    if ( a == 0)
    {
        return 0;
    }else if (a > 0)
    {
        som = n + soma(n, a-1);
        
    }
    
    
    return som;
}

int main(int argc, char const *argv[])
{
    int m;
    
    m = soma(10,4);
    printf("valor: %d",m);
    return 0;
}

