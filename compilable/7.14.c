int parseBin(const char binaryString[]) {
	int top = 0;
	char binarychar = 0;
	int ans = 0;

	while ( (binarychar = binaryString[top++]) ) {
		ans *= 2;
		ans += (binarychar - '0');
	}

	return ans;
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
	char line[100];
	readLine(line, 100);
	int dec = parseBin(line);
	printf("%d\n", dec);
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