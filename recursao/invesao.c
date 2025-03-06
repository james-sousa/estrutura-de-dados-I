#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void invert(char pl[], int ini, int fim){
    if (ini < fim)
    {
        char temp = pl[ini];
        pl[ini] = pl[fim];
        pl[fim] = temp;
        invert(pl,ini + 1, fim - 1);
    }
    
}

int main(int argc, char const *argv[])
{
    char pal[100];
    printf("Palavra: \n");
    scanf("%s",pal);
    int tam = strlen(pal);
    invert(pal,0,tam-1);
    printf("Invertida: %s\n",pal);
    return 0;
}
