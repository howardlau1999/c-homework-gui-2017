struct Result
{
	char LCS[100];
};

#include <string.h>
#define MAX(a,b) (a > b ? a : b)

void constructLCS(char dst[], char text[], int ans[][101], int ptr_i, int ptr_j) {
	if (ptr_i == 0 || ptr_j == 0) return;
	if (ans[ptr_i][ptr_j] == ans[ptr_i - 1][ptr_j]) {
		constructLCS(dst, text, ans, ptr_i - 1, ptr_j);
	} else if (ans[ptr_i][ptr_j] == ans[ptr_i][ptr_j - 1]) {
		constructLCS(dst, text, ans, ptr_i, ptr_j - 1);
	} else {
		constructLCS(dst, text, ans, ptr_i - 1, ptr_j - 1);
		dst[strlen(dst)] = text[ptr_i - 1];
	}
}

struct Result LCS(char text1[], char text2[]) {
    int ans[101][101] = {0};
    struct Result result = {0};

    int len1 = (int)strlen(text1);
    int len2 = (int)strlen(text2);

    for (int ptr_i = 0; ptr_i < len1; ptr_i ++) {
        for (int ptr_j = 0; ptr_j < len2; ptr_j ++) {
            if (text1[ptr_i] == text2[ptr_j]) {
                ans[ptr_i + 1][ptr_j + 1] = ans[ptr_i][ptr_j] + 1;
            } else {
                ans[ptr_i + 1][ptr_j + 1] = MAX(ans[ptr_i][ptr_j + 1], ans[ptr_i + 1][ptr_j]);
            }
        }
    }

	constructLCS(result.LCS, text1, ans, len1, len2);
    return result;
}


#include <stdio.h>

int main() {
	char text1[100];
	char text2[100];
	scanf("%s", text1);
	scanf("%s", text2);
	
	struct Result result = LCS(text1, text2);
	printf("%s", result.LCS);
}