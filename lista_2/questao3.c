#include <stdio.h>
#include <stdlib.h>

int *obtem_produtos_zerados(const int *codigo, const int *estoque, int num_produtos, int *num_zerados) {
    int *produtos_zerados = NULL;
    *num_zerados = 0;

    for (int i = 0; i < num_produtos; i++) {
        if (estoque[i] == 0) {
            (*num_zerados)++;
            produtos_zerados = (int *)realloc(produtos_zerados, *num_zerados * sizeof(int));

            if (produtos_zerados == NULL) {
                printf("Erro na alocação de memória.\n");
                exit(1);
            }

            produtos_zerados[*num_zerados - 1] = codigo[i];
        }
    }

    return produtos_zerados;
}

int main() {
    int codigo[] = {1, 2, 3, 4, 5};
    int estoque[] = {0, 2, 0, 7, 0};
    int num_produtos = sizeof(codigo) / sizeof(codigo[0]);
    int num_zerados;

    int *produtos_zerados = obtem_produtos_zerados(codigo, estoque, num_produtos, &num_zerados);

    if (num_zerados > 0) {
        printf("Códigos dos produtos com estoque zero: ");
        for (int i = 0; i < num_zerados; i++) {
            printf("%d ", produtos_zerados[i]);
        }
        printf("\n");

        free(produtos_zerados);
    } else {
        printf("Nenhum produto com estoque zero.\n");
    }

    return 0;
}