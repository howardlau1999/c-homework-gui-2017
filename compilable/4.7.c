#include <stdio.h>

void printInt(int val) {
	printf("%d", val); 
}

void printBit(int val, int bitPos) {
	int bit = (val >> bitPos) & 1;
	printInt(bit);
}

void printBits(int intVal) {
	int i = 0;
	while (i < 32) {
		printBit(intVal, 31 - i);
		i = i + 1;
	}
}

int main() {
	int a, b;
    scanf("%d %d", &a, &b);
    printBits(a);
    printf("\n");
    printBits(b);
    printf("\n");
    printBits(a & b);
    printf("\n");
    printBits(a | b);
    printf("\n");
    printBits(a ^ b);
    printf("\n");
    
    return 0;
}