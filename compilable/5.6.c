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

int main() {
    int primeCount, lineCount = 0, currentNumber = 2;
	scanf("%d", &primeCount);
	while(primeCount) {
		int prime = isPrime(currentNumber);
		primeCount -= prime;
		if (prime) {
			printf("%d ", currentNumber);
			lineCount++;
			if (lineCount % 10 == 0)
				printf("\n");
		}
		currentNumber++;
	}
    return 0;
}