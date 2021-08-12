char toLowercase(char c) {
	return c - ('A' - 'a');
}

#include <stdio.h>

char getChar() {
	char val;
	scanf("%c", &val);
	return val;
}

void printChar(char c) {
	printf("%c", c);
}

void testToLower() {
	char c = getChar();
	c = toLowercase(c);
	printChar(c);
}

int main() {
	for (int i = 0; i < 10; ++ i) {
		testToLower();
	}
}