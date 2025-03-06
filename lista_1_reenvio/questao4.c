#include <stdio.h>
#include <stdlib.h>

int reverse(int x, int reverso) {
    if (x == 0) {
        return reverso;
    } else {
        int digit = x % 10;
        reverso = reverso * 10 + digit;
        return reverse(x / 10, reverso);
    }
}

int main() {
    int x;
    printf("Digite um número inteiro: ");
    scanf("%d", &x);

    int reverso = reverse(x, 0);
    printf("Número invertido: %d\n", reverso);

    return 0;
}
