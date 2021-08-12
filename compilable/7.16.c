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

void swap(char *a, char *b) {
	char c = *a;
	*a = *b;
	*b = c;
}

void decToBin(const char dec[], char bin[]) {
	int number = atoi(dec);
	int top = 0;
	int remainder = 0;
	while (number) {
		remainder = number % 2;
		number /= 2;
		bin[top++] = '0' + remainder;
	}
	bin[top--] = 0;
	for (int i = 0; i < (top + 1) / 2; i++) {
		swap(&bin[i], &bin[top - i]);
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
	char dec[100], bin[100];
	readLine(dec, 100);
	decToBin(dec, bin);
	printf("%s\n", bin);
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