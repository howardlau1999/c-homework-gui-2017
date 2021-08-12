#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    printf("%d", a & 1);
    a = a >> 1;
    printf(" %d", a & 1);
    return 0;
}
