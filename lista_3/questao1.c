#include <stdio.h>

int power(int b, int p) {
    if (p == 0) {
        return 1;
    } else {
        return b * power(b, p - 1);
    }
}

int main() {
    int base = 2;
    int exponent = 3;
    int result = power(base, exponent);
    printf("%d^%d = %d\n", base, exponent, result);
    return 0;
}
