int gcd(int a, int b) {
	if (a < b) return gcd(b, a);
	int r = 0;
	
	while((r = a % b)) {
		a = b;
		b = r;
	}

	return b;
}

#include <stdio.h>

int getInt() {
	int val;
	scanf("%d", &val);
	return val;
}

void printInt(int val) {
	printf("%d", val); 
}

void test_gcd() {
	int num1 = getInt();
	int num2 = getInt();
	int result = gcd(num1, num2);
	printInt(result);
	putchar('\n');
}

int main() {
	for (int i = 0; i < 10; ++ i) {
		test_gcd();
	}
}