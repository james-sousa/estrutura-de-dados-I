#include <stdio.h>

void print_positive_integers(int K) {
    if (K >= 0) {
        printf("%d\n", K);
        print_positive_integers(K - 1);
    }
}

int main() {
    int K = 5;
    printf("Números inteiros positivos de %d até 0:\n", K);
    print_positive_integers(K);
    return 0;
}
