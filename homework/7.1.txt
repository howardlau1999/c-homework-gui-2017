#include <stdio.h>
#define N 10

// Input 10 integers and print them in the reversed order.

int main() {
	int nums[N] = {0};
	int i = 0;
	for (i = 0; i < N; i++) {
		scanf("%d", &nums[i]);
	}

	while (i-- > 0) {
		printf("%d ", nums[i]);
	}
	return 0;
}