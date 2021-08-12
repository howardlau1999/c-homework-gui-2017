int getDigit(char c) {
	if (c >= 'A' && c <= 'F') return (c - 'A' + 10);
	else if (c >= 'a' && c <= 'f') return (c - 'a' + 10);
	else if (c >= '0' && c <= '9') return (c - '0');
	return 0;
}

int parseHex(const char hexString[]) {
	int top = 0;
	char hexchar = 0;
	int ans = 0;

	while ( (hexchar = hexString[top++]) ) {
		ans *= 16;
		ans += getDigit(hexchar);
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
	int dec = parseHex(line);
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