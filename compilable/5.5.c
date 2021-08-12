#include <stdio.h>

// output chars between a and b

void displayBetween(char a, char b) {
	int charsCount = 0;
	if (a > b) displayBetween(b, a);
	for(; a <= b; a++) {
		printf("%c", a);
		charsCount++;
		if (charsCount % 10 == 0) {
			printf("\n");
		}
	}
}

int main() {
    char a, b;
	scanf("%c%c", &a, &b);
	displayBetween(a, b);
    return 0;
}