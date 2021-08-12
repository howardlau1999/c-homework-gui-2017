#include <stdio.h>

void printLine(int length, int nth) {
	for (int i = length - nth; i > 0; i--) {
		printf("0");
	}
	
	while (nth) {
		printf("1");
		nth--;
	}
	printf("\n");
}

int main() {
    int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		printLine(n, i);
	}
    return 0;
}