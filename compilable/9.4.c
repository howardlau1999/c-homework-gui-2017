#define MIN(a,b) (a<b?a:b)
#define MAX_LIMIT 9999999

// Find the minimum times needed to do a multiplication
int getMultiplications(int matLen, int dimensions[]) {
    int ans[10][10] = {0};

    for (int chainLen = 2; chainLen <= matLen; chainLen ++) {
        for (int begin = 1; begin <= matLen - chainLen + 1; begin ++) {
            int end = begin + chainLen - 1;
            ans[begin][end] = MAX_LIMIT;
            for (int split = begin; split < end; split ++) {
                int attempt = ans[begin][split] + ans[split + 1][end] + \
                            dimensions[begin - 1] * dimensions[split] * dimensions[end];
                if (attempt < ans[begin][end]) ans[begin][end] = attempt;
            }
        }
    }

    return ans[1][matLen];
}
#include <stdio.h>

int main() {
	int dimensions[10];
	for (int i = 0; i < 10; ++ i) {
		scanf("%d", &dimensions[i]);
	}
	printf("%d", getMultiplications(9, dimensions));
}