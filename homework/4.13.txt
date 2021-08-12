#include <stdio.h>

int main() {
    int i = 5;
	double n = 0;
    while(i--) {
		scanf("%lf", &n);
        for (int j = 0; j < 100; j += 10) {
			if (j < n && n <= j + 10) {
				printf("(%d,%d]\n", j, j + 10);
                break;
			}
		}
    }
    return 0;
}