#include <stdio.h>

int hasOccured(int *nums, int len, int key) {
	for (int i = 0; i < len; i++) {
		if (key == nums[i]) return 1;
	}
	return 0;
} 

int readLineDistinct(int data[], int max) {
	int input = 0;
	int top = 0;
	int reading = 0;
	char c = 0;
	while (top < max) {
		while (1) {
			c = getchar();
			if (c != ' ') break;
		}
		if (c == '\n') return top;
		if (c != ' ' && !reading) {
			reading = 1;
			input = 0;

			while (reading) {
				if (c == ' ') break;
				if (c == '\n') {
					if (!hasOccured(data, top, input)) data[top++] = input;
					return top;
				}
				input *= 10;
				input += (c - '0');
				c = getchar();
			}

			reading = 0;
		}
		if (!hasOccured(data, top, input))
			data[top++] = input;
	}

	while (1) {
		c = getchar();
		if (c == '\n') return top;
	}

	return top;
}

#include <stdio.h>

void print(int data[], int length) {
	for (int i = 0; i < length; ++ i) {
		printf("%d ", data[i]);
	}
	putchar('\n');
}

int main() {
	for (int i = 0; i < 2; ++ i) {
		int data[10];
		int count = readLineDistinct(data, 10);
		print(data, count);
	}
}