#include <stdio.h>
// n is the length of stars! not the flag
void printStars(int n, int shift) {
	int isStar = !shift;
	char c[2] = {' ', '*'};
	
	for(int i = 1; i <= n; i++) {
		putchar(c[isStar]);
		isStar = !isStar;
	}
}
// print bars with width n
void printBars(int n, int isBlank) {
	char c[2] = {'=', ' '};
	for(int i = 1; i <= n; i++) {
		putchar(c[isBlank]);
	}
}
// print out m * n flag
void printFlag(int m, int n) {
	int barWidth = n / 2, starWidth = n / 2;
	int starHeight = m / 2 - 1;
	int barHeight = m;
	for(int line = 0; line < m; line++) {
		if (line <= starHeight) {
			printStars(starWidth, line % 2);
			printBars(barWidth, line % 2);
		} else {
			printBars(barWidth * 2, line % 2);
		}
		printf("\n");
	}
}
int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	printFlag(m, n);
    return 0;
}