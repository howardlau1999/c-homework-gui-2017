// convert string to integer
int atoi(const char array[]) {
	int ans = 0;
	int i = 0;
	while ( array[i] && array[i] != ' ') {
		ans *= 10;
		ans += (array[i++] - '0');
	}
	return ans;
}


char hexChar(int c) {
	if (c <= 9) return c + '0';
	if (c >= 10) return c - 10 + 'A';
	return 0;
}

void swap(char *a, char *b) {
	char c = *a;
	*a = *b;
	*b = c;
}

void decToHex(const char dec[], char hex[]) {
	int number = atoi(dec);
	int top = 0;
	int remainder = 0;
	while (number) {
		remainder = number % 16;
		number /= 16;
		hex[top++] = hexChar(remainder);
	}
	hex[top--] = 0;
	for (int i = 0; i < (top + 1) / 2; i++) {
		swap(&hex[i], &hex[top - i]);
	}
}

#include <stdio.h>

int readLine(char buf[], int bufSize) {
	int i;
	for (i = 0; ; ++ i) {
		int c = getchar();
		if (c == EOF || c == '\n' || i == bufSize - 1) {
			buf[i] = 0;
			return i;
		}
		buf[i] = c;
	}
}

void test() {
	char dec[100], hex[100];
	readLine(dec, 100);
	decToHex(dec, hex);
	printf("%s\n", hex);
}

int main() {
	int times;
	scanf("%d", &times);
	char temp[100];
	readLine(temp, 100);
	int i;
	for (i = 0; i < times; ++ i) {
		test();
	}
}