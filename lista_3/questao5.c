#include <stdio.h>

double compound_interest(double principal, double rate, int months) {
    if (months == 0) {
        return principal;
    } else {
        return compound_interest(principal * (1 + rate), rate, months - 1);
    }
}

int main() {
    double principal = 1000.0;
    double rate = 0.05;
    int months = 12;
    double final_amount = compound_interest(principal, rate, months);
    printf("Juros compostos após %d meses: %.2f\n", months, final_amount);
    return 0;
}
