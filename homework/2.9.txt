#include <stdio.h>

int main() {
    double a;
    scanf("%lf", &a);
    long int b = a;
    printf("%ld\n%lf", b, a-b);
    return 0;
}
