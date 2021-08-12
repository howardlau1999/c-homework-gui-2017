// swap
void swap(double *a, double *b) {
	double t = *a;
	*a = *b;
	*b = t;
}

// sort
void sort(double * a, double * b, double * c) {
	if (*a > *b) swap(a, b);
	if (*b > *c) swap(b, c);
	if (*a > *b) swap(a, b);
}


#include <stdio.h>

void test() {
	double num1, num2, num3;
	scanf("%lf %lf %lf", &num1, &num2, &num3);
	sort(&num1, &num2, &num3);
	printf("%lf %lf %lf\n", num1, num2, num3);
}

int main() {
	for (int i = 0; i < 10; ++ i) {
		test();
	}
}