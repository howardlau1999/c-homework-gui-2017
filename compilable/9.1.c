int getMaxCuttingPrice(int prices[][2], int priceCount, int rodLength) {
	int maxPrice = 0;
	if (rodLength == 0) return 0;

	for (int i = 0; i < priceCount; ++i) {
		if (prices[i][0] <= rodLength) {
			int attempt = getMaxCuttingPrice(prices, priceCount, rodLength - prices[i][0]) + prices[i][1];
			if (attempt > maxPrice) maxPrice = attempt;
		}
	}

	return maxPrice;
}


#include <stdio.h>

void readPriceTable(int prices[][2], int priceCount) {
	for (int i = 0; i < priceCount; ++ i) {
		scanf("%d", &prices[i][0]);
	}
	for (int i = 0; i < priceCount; ++ i) {
		scanf("%d", &prices[i][1]);
	}
}

void test(int prices[][2], int priceCount) {
	int rodLength;
	scanf("%d", &rodLength);
	printf("%d\n", getMaxCuttingPrice(prices, priceCount, rodLength));
}

int main() {
	int prices[6][2];
	readPriceTable(prices, 6);
	
	for (int i = 0; i < 10; ++ i) {
		test(prices, 6);
	}
}