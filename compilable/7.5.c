#include <stdio.h>
#define MAX_LEN 100

char getGrade(int score, int highest) {
	char grade = 'A';
	if (score >= highest - 10) grade = 'A';
	else if (score >= highest - 20) grade = 'B';
	else if (score >= highest - 30) grade = 'C';
	else if (score >= highest - 40) grade = 'D';
	else grade = 'F';

	return grade;
}

int main() {
	int input = 0;
	int highest = -10000;
	int grades[MAX_LEN] = {0};
	int top = 0;

	while (scanf("%d", &input) != EOF) {
		if (input > highest) highest = input;
		grades[top++] = input;
	}

	for (int i = 0; i < top; i++) {
		putchar(getGrade(grades[i], highest));
	}

	return 0;
}