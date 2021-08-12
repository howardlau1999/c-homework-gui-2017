#include <stdio.h>

// reverse a integer
int reverseNum(int num) {
	int ans = 0;
	while (num) {
		ans *= 10;
		ans += (num % 10);
		num /= 10;
	}
	return ans;
}

int main() {
    int num;
	while(scanf("%d", &num) != EOF) {
		printf("%d\n", reverseNum(num));
	}
    return 0;
}