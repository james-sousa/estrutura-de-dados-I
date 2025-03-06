#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int tam;
    char *ptc;

    printf("Digite o tamanho da sua string: ");
    scanf("%d",&tam);

    ptc = (char *)malloc((tam + 1) * sizeof(char));

    if (ptc == NULL)
    {
        printf("Erro na alocação de memoria");
        return 1;
    }

    printf("Digite a sua string: ");
    scanf("%s", ptc);

    printf("Sua string eh: %s",ptc);
    free(ptc);
    
    
    return 0;
}
