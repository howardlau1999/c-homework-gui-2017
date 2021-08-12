
// return the length of a string
int strlen(const char text[]) {
	int len = 0;
	while (text[len] != '\0') len++;
	return len;
}

// copy strings
void strcpy(char to[], const char from[]) {
	for (int i = 0; i <= strlen(from); i++) 
		to[i] = from[i];
}

// concatenate two strings
void strcat(char to[], const char from[]) {
	int tolen = strlen(to);
	for (int i = 0; i <= strlen(from); i++) {
		to[i + tolen] = from[i];
	}
}

// compare two strings
int strcmp(const char s1[], const char s2[]) {
	int delta = 0;
	int top = 0;

	while ((delta = s1[top] - s2[top]) == 0) {
		if (s1[top] == '\0') break;
		top++;
	}

	return delta;
}

// convert string to integer
int atoi(const char array[]) {
	int ans = 0;
	int i = 0;
	int negative = 1;
	if (array[i++] == '-') negative = -1;
	else i--; 
	for (; i < strlen(array); i++) {
		ans *= 10;
		ans += (array[i] - '0');
	}

	return ans * negative;
}

// convert integer to string
void itoa(int value, char array[]) {
	int base = 1;
	int top = 0;
	if (value < 0) {
		value = -value;
		array[top++] = '-';
	}
	while (base * 10 <= value) base *= 10;
	while (base) {
		char digit = '0' + value / base % 10;
		array[top++] = digit;
		base /= 10;
	}

	array[top] = '\0';
}

// substring
void substring(char to[], const char text[], int start, int len) {
	for (int i = 0; i < len; i++)
		to[i] = text[i + start];
	to[len] = '\0';
}

// insertion
void insert(char to[], int at, const char ins[]) {
	int oldlen = strlen(to);
	int deltapos = strlen(ins);
	// move all characters after at (inc.)
	for (int i = oldlen; i >= at; --i)
		to[i + deltapos] = to[i];

	for (int i = 0; i < strlen(ins); i++)
		to[i + at] = ins[i];
}
#include <stdio.h>

int main() {
	char text1[100];
	char text2[100];
	
	scanf("%s", text1);
	printf("length %ld\n", strlen(text1));
	
	strcpy(text2, text1);
	printf("strcpy %s\n", text2);
	
	scanf("%s", text1);
	strcat(text2, text1);
	printf("strcat %s\n", text2);
	
	scanf("%s", text2);
	printf("strcmp %d\n", strcmp(text1, text2));
	
	scanf("%s", text1);
	scanf("%s", text2);
	printf("atoi %d %d\n", atoi(text1), atoi(text2));
	
	int number1, number2;
	scanf("%d %d", &number1, &number2);
	itoa(number1, text1);
	itoa(number2, text2);
	printf("itoa %s %s\n", text1, text2);
	
	int start, len;
	scanf("%s %d %d", text1, &start, &len);
	substring(text2, text1, start, len);
	printf("substring %s\n", text2);
	
	scanf("%s", text2);
	insert(text1, start, text2);
	printf("insert %s\n", text1);
}