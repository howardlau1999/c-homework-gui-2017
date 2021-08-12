/*
An approximated sinusoid function using
	sin(x) ¡Ö x - x^3/3! + x^5/5!
*/
double sin(double x) {
	double x2 = x * x;
	double x3 = x2 * x;
	double x5 = x3 * x2;
	double fib3 = 2 * 3;
	double fib5 = fib3 * 4 * 5;
	return x - x3 / fib3 + x5 / fib5;
}

#define PI 3.14
#include <stdio.h>

int main() {
    printf("%lf", sin(PI/6));
    return 0;
}