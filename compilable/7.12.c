int isAlphabit(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' || c <= 'Z');
}

int getIndex(char c) {
	if (c >= 'A' && c <= 'Z') return (c - 'A');
	else return (c - 'a');
}

void count(const char line[], int array[]) {
	char chara = 0;
	int top = 0;
	
	for (int i = 0; i < 26; i++) array[i] = 0;

	while ( (chara = line[top++]) ) {
		if (!isAlphabit(chara)) continue;
		array[getIndex(chara)]++;
	}
}
#include <stdio.h>

int readLine(char buf[], int bufSize) {
	int i;
	for (i = 0; ; ++ i) {
		int c = getchar();
		if (c == EOF || c == '\n' || i == bufSize - 1) {
			buf[i] = 0;
			return i;
		}
		buf[i] = c;
	}
}

void test() {
	char line[100];
	readLine(line, 100);
	int array[26];
	count(line, array);
	int i;
	for (i = 0; i < 26; ++ i) {
		printf("%d ", array[i]);
	}
	putchar('\n');
}

int main() {
	int times;
	scanf("%d", &times);
	char temp[100];
	readLine(temp, 100);
	int i;
	for (i = 0; i < times; ++ i) {
		test();
	}
}