int sumDigits(int num) {
	int sum = 0;
	while (num) {
		sum += (num % 10);
		num /= 10;
	}
	return sum;
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

void testSumDigits() {
	int number = getInt();
	int sum = sumDigits(number);
	printInt(sum);
	putchar('\n');
}

int main() {
	for (int i = 0; i < 10; ++ i) {
		testSumDigits();
	}
}