#define bool int
// returns true if a character is between '0' and '9'.

bool isDigit(char c) {
	return (c >= '0' && c <= '9');
}

// returns true if a character is between 'a' and 'z'.

bool isLower(char c) {
	return (c >= 'a' && c <= 'z');
}

// returns true if a character is between 'A' and 'Z'.

bool isUpper(char c) {
	return (c >= 'A' && c <= 'Z');
}


// returns true if a character isLower or isUpper.  

bool isAlphabit(char c) {
	return (isLower(c) || isUpper(c));
}

// returns true if a character isAlphabit or isDigit.  

bool isAlphabitOrNumber(char c) {
	return (isAlphabit(c) || isDigit(c));
}

// returns true if a character is one of ' ', '\t', '\r', or '\n'.  

bool isSpace(char c) {
	return (c == ' ' || c == '\t' || c == '\r' || c == '\n');
}

// returns true if a character is between '!' and '~'.

bool isPrintable(char c) {
	return (c >= '!' && c <= '~');
}

// returns true if a character isPrintable but not isSpace.  

bool isGraphical(char c) {
	return (isPrintable(c) && !isSpace(c));
}


// returns true if a character isGraphical but not isAlphabitOrNumber.  

bool isPunctuation(char c) {
	return (isGraphical(c) && !isAlphabitOrNumber(c));
}
#include <stdio.h>

int inputInt() {
	int val;
	scanf("%d", &val);
	return val;
}

int inputChar() {
	char val;
	scanf("%c", &val);
	return val;
}

int main() {
	int times = inputInt();
	inputChar(); // read '\n'
	for (int i = 0; i < times; ++ i) {
		char c = inputChar();
		printf("isDigit(%c) = %d\n", c, isDigit(c));
		printf("isLower(%c) = %d\n", c, isLower(c));
		printf("isUpper(%c) = %d\n", c, isUpper(c));
		printf("isAlphabit(%c) = %d\n", c, isAlphabit(c));
		printf("isAlphabitOrNumber(%c) = %d\n", c, isAlphabitOrNumber(c));
		printf("isSpace(%c) = %d\n", c, isSpace(c));
		printf("isPrintable(%c) = %d\n", c, isPrintable(c));
		printf("isGraphical(%c) = %d\n", c, isGraphical(c));
		printf("isPunctuation(%c) = %d\n", c, isPunctuation(c));
		putchar('\n');
	}
}