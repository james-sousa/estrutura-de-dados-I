#include <stdio.h>

int sum_positive_integers(int K) {
    if (K == 0) {
        return 0;
    } else {
        return K + sum_positive_integers(K - 1);
    }
}

int main() {
    int K = 5;
    int sum = sum_positive_integers(K);
    printf("Soma de números inteiros positivos de %d até 0: %d\n", K, sum);
    return 0;
}
