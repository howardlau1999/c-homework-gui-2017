double sqrt(double n);

// check if a number is prime number

int isPrime(int num) {
	double root = sqrt(num);

	for (int i = 2; i <= root; i++) {
		if (num % i == 0) return 0;
	}

	return 1;
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

void testIsPrime() {
	int number = getInt();
	char c = isPrime(number) ? 'T' : 'F';
	putchar(c);
}

int main() {
	for (int i = 0; i < 10; ++ i) {
		testIsPrime();
	}
}