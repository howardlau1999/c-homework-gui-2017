#define bool int
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

int isAnagram(char s1[], char s2[]) {
	sort(s1); sort(s2);
	int len1 = 0, len2 = 0;
	while(s1[len1]) len1++;
	while(s2[len2]) len2++;
	if (len1 != len2) return 0;
	while (len1--) if (s1[len1] != s2[len1]) return 0;
	return 1;
}
#include <stdio.h>

void test() {
	char s1[100], s2[100];
	scanf("%s", s1);
	scanf("%s", s2);
	bool res = isAnagram(s1, s2);
	printf("%s\n", (res ? "true" : "false"));
}

int main() {
	int times;
	scanf("%d", &times);
	int i;
	for (i = 0; i < times; ++ i) {
		test();
	}
}