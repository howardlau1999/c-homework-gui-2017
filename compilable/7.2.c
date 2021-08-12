#include <stdio.h>

// Find the max of 10 numbers.
int main() {
	int input = 0;
	int max = -10000;
	while (scanf("%d", &input) != EOF) {
		if (input > max) max = input;
	}
	printf("%d", max);
	return 0;
}