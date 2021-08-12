#include <stdio.h>
int isLetter(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int countLetters(const char* line) {
	int top = 0;
	int ans = 0;
	char c = 0;
	while ( (c = line[top++]) ) ans += isLetter(c);
	return ans; 
}

int get_line(char text[], int limit) {
	int i;
	for (i = 0; ; ++ i) {
		int c = getchar();
		if (c == EOF || c == '\n' || i == limit - 1) {
			text[i] = 0;
			return i;
		}
		text[i] = c;
	}
}

void test() {
	char line[100];
	get_line(line, 100);
	printf("%d\n", countLetters(line));
}

int main() {
	int times;
	scanf("%d", &times);
	char temp[100];
	get_line(temp, 100);
	int i;
	for (i = 0; i < times; ++ i) {
		test();
	}
}