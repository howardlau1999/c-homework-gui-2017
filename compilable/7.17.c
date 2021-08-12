void swap(char *a, char *b) {
	char c = *a;
	*a = *b;
	*b = c;
}

int partition(char array[], int lo, int hi) {
	int pivot = array[lo];
	int i = lo, j = hi + 1;
	while (1) {
		while (array[++i] <= pivot) 
			if (i == hi) break;
		while (array[--j] >= pivot)
			if (j == lo) break;
		if (i >= j) break;
		swap(&array[i], &array[j]);
	}
	swap(&array[lo], &array[j]);
	return j;
}

void quicksort(char array[], int lo, int hi) {
	if (hi <= lo) return;
	int mid = lo + (hi - lo) / 2;
	int j = partition(array, lo, hi);
	quicksort(array, lo, j - 1);
	quicksort(array, j + 1, hi);
}

void sort(char str[]) {
	int len = 0;
	while (str[len++]);
	len -= 2;
	quicksort(str, 0, len);
}
#include <stdio.h>

int readLine(char buf[], int bufSize) {
	int i;
	for (i = 0; ; ++ i) {
		int c = getchar();
		if (c == EOF || c == '\n' || i == bufSize - 1) {
			buf[i] = 0;
			return i;
		}
		buf[i] = c;
	}
}

void test() {
	char text[100];
	readLine(text, 100);
	sort(text);
	printf("%s\n", text);
}

int main() {
	int times;
	scanf("%d", &times);
	char temp[100];
	readLine(temp, 100);
	int i;
	for (i = 0; i < times; ++ i) {
		test();
	}
}