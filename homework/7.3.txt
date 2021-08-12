#include <stdio.h>
#define maxN 10

// Find the number that occurs the most times among 100 integers.
int main() {
	int occur[maxN + 1] = {0};
	int ans, input, maxOccurence;
	ans = 0;
	maxOccurence = 0;
	while (scanf("%d", &input) != EOF) {
		occur[input]++;
		if (occur[input] > maxOccurence) {
			ans = input;
			maxOccurence = occur[input];
		}
	}

	printf("%d %d", ans, maxOccurence);
	return 0;
}