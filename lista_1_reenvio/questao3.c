#include <stdio.h>
#include <stdlib.h>

long long int calcula(int x, int y) {
    if (y == 0) {
        return 1;
    } else {
        long long int temp = calcula(x, y / 2);
        if (y % 2 == 0) {
            return temp * temp;
        } else {
            return x * temp * temp;
        }
    }
}

int main() {
    int x, y;
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    printf("Digite o valor de y: ");
    scanf("%d", &y);

    long long int resultado = calcula(x, y);
    printf("%d^%d = %lld\n", x, y, resultado);

    return 0;
}
