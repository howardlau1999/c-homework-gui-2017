#include <stdio.h>

int reverseNum(int num) {
	int ans = 0;
	while (num) {
		ans *= 10;
		ans += (num % 10);
		num /= 10;
	}
	return ans;
}

int isPalindromic(int num) {
	return reverseNum(num) == num;
}

double sqrt(double n);

// check if a number is prime number

int isPrime(int num) {
	double root = sqrt(num);

	for (int i = 2; i <= root; i++) {
		if (num % i == 0) return 0;
	}

	return 1;
}

int isPalindromicPrime(int num) {
	return isPalindromic(num) && isPrime(num);
}

int main() {
    int palindromicPrimeCount, lineCount = 0, currentNumber = 2;
	scanf("%d", &palindromicPrimeCount);
	while(palindromicPrimeCount) {
		int palindromicPrime = isPalindromicPrime(currentNumber);
		palindromicPrimeCount -= palindromicPrime;
		if (palindromicPrime) {
			printf("%d ", currentNumber);
			lineCount++;
			if (lineCount % 10 == 0) printf("\n");
		}
		currentNumber++;
	}
    return 0;
}