#include <stdio.h>
// #include "sum.h"
// #include "minus.h"

extern int sum(int a, int b);
extern int minus(int a, int b);

int main() {
    int a = 10, b = 5;

    int sum_result = sum(a, b);
    printf("Sum: %d\n", sum_result);

    int minus_result = minus(a, b);
    printf("Minus: %d\n", minus_result);

    return 0;
}
