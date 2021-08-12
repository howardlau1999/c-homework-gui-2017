#include <stdio.h>

int gcd(int a, int b) {
	int r;
	if (a < b) return gcd(b, a);
	while ((r = a % b)) {
		a = b;
		b = r;
	}
	return b;
}

int main() {
    int a, b;
	while(scanf("%d %d", &a, &b) != EOF) {
		printf("%d\n", gcd(a, b));
	}
    return 0;
}