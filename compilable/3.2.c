double cos(double x) {
    double x2 = x * x;
    double x4 = x2 * x2;
    double x6 = x4 * x2;
    double fac2 = 2;
    double fac4 = 4 * 3 * fac2;
    double fac6 = 6 * 5 * fac4;
    return 1 - x2 / fac2 + x4 / fac4 -x6 / fac6;
}
#include <stdio.h>
#define PI 3.14

int main() {
	printf("%lf\n", cos(0));
	printf("%lf\n", cos(PI / 6));
	printf("%lf\n", cos(PI / 4));
	printf("%lf\n", cos(PI / 3));
	printf("%lf\n", cos(PI / 2));
}