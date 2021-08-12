#include <stdio.h>
#define maxN 10

int hasOccured(int *nums, int len, int key) {
	for (int i = 0; i <= len; i++) {
		if (key == nums[i]) return 1;
	}
	
	return 0;
} 

int main() {
	int times[maxN + 1] = {0};
	int order[maxN + 1] = {0};
	int top = 0, input;
	
	while (scanf("%d", &input) != EOF) {
		if (!hasOccured(order, top, input)) {
			order[top++] = input;
		}
		times[input]++;
	}

	for (int i = 0; i <= maxN; i++) {
		printf("%d %d\n", order[i], times[order[i]]);
	}

	return 0;
}