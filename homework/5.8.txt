#include <stdio.h>

double sqrt(double n);

// check if a number is prime number

int isPrime(int num) {
	double root = sqrt(num);

	for (int i = 2; i <= root; i++) {
		if (num % i == 0) return 0;
	}

	return 1;
}

// return a number in its reversed form

int reverseNum(int num) {
	int ans = 0;
	while (num) {
		ans *= 10;
		ans += (num % 10);
		num /= 10;
	}
	return ans;
}

// return if a number is an emirp

int isEmirp(int num) {
	return isPrime(num) && isPrime(reverseNum(num));
}

int main() {
    int emirpCount, lineCount = 0, currentNumber = 2;
	scanf("%d", &emirpCount);
	while(emirpCount) {
		int emirp = isEmirp(currentNumber);
		emirpCount -= emirp;
		if (emirp) {
			printf("%d ", currentNumber);
			lineCount++;
			if (lineCount % 10 == 0) printf("\n");
		}
		currentNumber++;
	}
    return 0;
}