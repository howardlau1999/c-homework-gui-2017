#include <string.h>
#define MAX(a,b) (a > b ? a : b)
int work(char text1[], char text2[], int ptr_i, int ptr_j) {
    if (ptr_i == -1 || ptr_j == -1) return 0;
    if (text1[ptr_i] == text2[ptr_j]) {
        ptr_i --;
        ptr_j --;
        return work(text1, text2, ptr_i, ptr_j) + 1;
    } else {
        return MAX(work(text1, text2, ptr_i - 1, ptr_j), work(text1, text2, ptr_i, ptr_j - 1));
    }
}

int LCS(char text1[], char text2[]) {
    int ptr_i = (int)strlen(text1) - 1;
    int ptr_j = (int)strlen(text2) - 1;
    return work(text1, text2, ptr_i, ptr_j);
}


#include <stdio.h>

int main() {
	char text1[100];
	char text2[100];
	scanf("%s", text1);
	scanf("%s", text2);
	
	printf("%d", LCS(text1, text2));
}