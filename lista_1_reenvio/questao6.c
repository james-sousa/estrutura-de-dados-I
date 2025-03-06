#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *subtrai(const char *s1, const char *s2) {
    int ocorrencias[256] = {0}; // Inicializa um array para contar as ocorrências de caracteres em s2

    // Conta as ocorrências de caracteres em s2
    for (int i = 0; s2[i] != '\0'; i++) {
        ocorrencias[(int)s2[i]] = 1;
    }

    int tamanho_resultado = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (!ocorrencias[(int)s1[i]]) {
            tamanho_resultado++;
        }
    }

    char *resultado = (char *)malloc((tamanho_resultado + 1) * sizeof(char)); // Aloca memória para o resultado

    if (resultado == NULL) {
        printf("Erro na alocação de memória.\n");
        return NULL;
    }

    int pos = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (!ocorrencias[(int)s1[i]]) {
            resultado[pos] = s1[i];
            pos++;
        }
    }

    resultado[pos] = '\0'; // Adiciona o caractere nulo no final da string

    return resultado;
}

int main() {
    char *s1 = "abacadef";
    char *s2 = "ae";

    char *resultado = subtrai(s1, s2);

    if (resultado != NULL) {
        printf("Resultado: %s\n", resultado);
        free(resultado);
    }

    return 0;
}
