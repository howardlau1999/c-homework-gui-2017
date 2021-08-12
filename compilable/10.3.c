#include <stdio.h>

struct Goods
{
	int number;
	int weight;
	int price;
};

void read(struct Goods * goods) {
	scanf("%d %d %d\n", &goods->number, 
			&goods->weight, &goods->price);
}

void readArray(struct Goods goods[], int size) {
	for (int i = 0; i < size; ++ i) {
		read(&goods[i]);
	}
}

void print(const struct Goods * goods) {
	printf("%d %d %d\n", goods->number, 
			goods->weight, goods->price);
}

void printArray(const struct Goods goods[], int size) {
	for (int i = 0; i < size; ++ i) {
		print(&goods[i]);
	}
}

// sort
void sort(const struct Goods *goods[], int size) {
	for (int i = size; i > 0; i --) {
		for (int j = 0; j < i - 1; j ++) {
			if (goods[j]->price > goods[j + 1]->price) {
				const struct Goods *t = goods[j];
				goods[j] = goods[j + 1];
				goods[j + 1] = t;
			}
		}
	}
}



void printGoods(const struct Goods * address[], int size) {
	for (int i = 0; i < size; ++ i) {
		print(address[i]);
	}
}

int main() {
	struct Goods goods[10];
	readArray(goods, 10);
	
	const struct Goods * addresses[10];
	for (int i = 0; i < 10; ++ i) {
		addresses[i] = &goods[i];
	}
	sort(addresses, 10);
	
	printArray(goods, 10);
	printf("\n");
	printGoods(addresses, 10);
}