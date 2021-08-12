#include <stdio.h>
void countDigits(const char *s, int ans[]) {
	int i;
	int top = 0;
	char c = 0;
	for (i = 0; i < 10; i++) ans[i] = 0;
	while ( (c = s[top++]) ) {
		ans[c - '0']++;
	}
}

void printIntArray(int array[], int length) {
	for (int i = 0; i < length; ++ i) {
		printf("%d ", array[i]);
	}
	putchar('\n');
}

void countDigitTest() {
	char digits[100];
	scanf("%s", digits);
	int count[10];
	countDigits(digits, count);
	printIntArray(count, 10);
}

int main() {
	int times;
	scanf("%d", &times);
	for (int i = 0; i < times; ++ i) {
		countDigitTest();
	}
}