#include <stdio.h>
#define PI 3.14


int main() {
    double r, h;
    scanf("%lf %lf", &r, &h);
    printf("%lf", r * r * h * PI);
    return 0;
}