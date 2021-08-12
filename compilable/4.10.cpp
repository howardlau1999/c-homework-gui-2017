#include <iostream>
using namespace std;

void printInt(int val) {
	cout << val;
}

void printBit(char val, int bitPos) {
	int bit = (val >> bitPos) & 1;
	printInt(bit);
}

void printBits(char val) {
	int i = 0;
	while (i < 8) {
		printBit(val, 7 - i);
		i = i + 1;
	}
}

int main() {
    char c;
    scanf("%c", &c);
    printBits(c);
    printf("\n");
    c >>= 5;
    c <<= 3;
    printBits(c);
    return 0;
}