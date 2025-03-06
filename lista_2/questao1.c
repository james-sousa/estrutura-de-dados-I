#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int linhas = 100;
    int colunas = 100;

    
    int** matriz = (int**)calloc(linhas, sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*)calloc(colunas, sizeof(int));
    }

   
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = 0;
        }
    }

    
    int retangulo_linhas = linhas / 2;
    int retangulo_colunas = colunas / 2;

    
    for (int i = 0; i < retangulo_linhas; i++) {
        for (int j = 0; j < retangulo_colunas; j++) {
            matriz[i][j] = 1;
        }
    }

    
    int centro_x = retangulo_linhas / 2;
    int centro_y = retangulo_colunas / 2;

    
    int raio = (retangulo_linhas < retangulo_colunas) ? retangulo_linhas / 2 : retangulo_colunas / 2;

    
    for (int i = -raio; i <= raio; i++) {
        for (int j = -raio; j <= raio; j++) {
            if (i * i + j * j <= raio * raio) {
                int x = centro_x + i;
                int y = centro_y + j;
                if (x >= 0 && x < linhas && y >= 0 && y < colunas) {
                    matriz[x][y] = 2;
                }
            }
        }
    }

    
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == 0) {
                printf("\033[34m"); 
            } else if (matriz[i][j] == 1) {
                printf("\033[30m"); 
            } else if (matriz[i][j] == 2) {
                printf("\033[33m"); 
            }
            printf("%d ", matriz[i][j]);
            printf("\033[0m"); 
        }
        printf("\n");
    }

    
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
