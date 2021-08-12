#include <stdio.h>

// calculate sum of each digit

int calculateSum(int num) {
	int sum = 0;
	while (num) {
		sum += (num % 10);
		num /= 10;
	}
	return sum;
}

int main() {
    int num;
	while(scanf("%d", &num) != EOF) {
		printf("%d\n", calculateSum(num));
	}
    return 0;
}