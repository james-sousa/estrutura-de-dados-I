#include <stdio.h>

int sum_between(int A, int B) {
    if (A > B) {
        return 0;
    } else {
        return A + sum_between(A + 1, B);
    }
}

int main() {
    int A = 1;
    int B = 5;
    int sum = sum_between(A, B);
    printf("Soma de números entre %d e %d: %d\n", A, B, sum);
    return 0;
}
