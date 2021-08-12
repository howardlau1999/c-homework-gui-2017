#include <stdio.h>
#include <string.h>
#define MAX_LEN 100000

// read in a string
void readStr(char str[]) {
	int len = 0;
	int chara = 0;
	while ( ( chara = getchar() ) != EOF ) {
		str[len ++ ] = chara;
	}
	str[len] = 0;
}

// replace keyword in src and save the result in dst
void strrpl(char *dst, char *src, char *keyword, char *replacement) {
	char before[MAX_LEN] = {0};
	char *after;
	while ( ( after = strstr(src, keyword) ) != NULL) {
		memset(before, 0, MAX_LEN * sizeof(char));
		strncpy(before, src, strlen(src) - strlen(after));
		strcat(dst, before);
		strcat(dst, replacement);
		src = after + strlen(keyword);
	}
	if ( strlen(src) )
		strcat(dst, src);
}

int main() {
	char str[MAX_LEN] = {0};
	char result[MAX_LEN] = {0};
	readStr(str);
	
	strrpl(result, str, "C++", "JAVA");
	printf("%s", result);
	
	return 0;
}