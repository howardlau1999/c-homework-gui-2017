int knapsack(int prices[], int weights[], int maxWeight) {
    int ans[100000] = {0};
    for (int bpWeight = 1; bpWeight <= maxWeight; bpWeight ++) {
        int max = ans[bpWeight - 1];
		for (int thingIndex = 0; thingIndex < 10; thingIndex ++) {
            if (bpWeight >= weights[thingIndex]) {
                int attempt = ans[bpWeight - weights[thingIndex]] + prices[thingIndex];
                if (attempt > max)
                    max = attempt;
            }    
        }
		ans[bpWeight] = max;
    }
    return ans[maxWeight];
}
#include <stdio.h>

void read(int array[], int length) {
	for (int i = 0; i < length;  ++ i) {
		scanf("%d", &array[i]);
	}
}

int main() {
	int prices[10];
	read(prices, 10);
	int weights[10];
	read(weights, 10);
	int maxWeight;
	scanf("%d", &maxWeight);
	
	printf("%d", knapsack(prices, weights, maxWeight)); 
}