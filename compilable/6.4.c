int largest(int a, int b, int c) {
	int nums[3] = {a, b, c};
	int max = -1;
	for (int i = 0; i < 3; i++) {
		if (nums[i] > max) max = nums[i];
	}
	return max;
}

#include <stdio.h>

int getInt() {
	int val;
	scanf("%d", &val);
	return val;
}

void printInt(int val) {
	printf("%d", val); 
}

void testLargest() {
	int num1 = getInt();
	int num2 = getInt();
	int num3 = getInt();
	int result = largest(num1, num2, num3);
	printInt(result);
	putchar('\n');
}

int main() {
	for (int i = 0; i < 10; ++ i) {
		testLargest();
	}
}