int reverse(int num) {
	int ans = 0;
	while (num) {
		ans *= 10;
		ans += (num % 10);
		num /= 10;
	}
	return ans;
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

void testReverse() {
	int number = getInt();
	int reversed = reverse(number);
	printInt(reversed);
	putchar('\n');
}

int main() {
	for (int i = 0; i < 10; ++ i) {
		testReverse();
	}
}