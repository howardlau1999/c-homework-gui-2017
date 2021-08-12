#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", (
	(10 < n && n <= 20) ||
	(30 <= n && n <=40) ||
	(50 <= n && n < 60) 
	));
    scanf("%d", &n);
    printf("%d\n", (
	(10 < n && n <= 20) ||
	(30 <= n && n <=40) ||
	(50 <= n && n < 60) 
	));
    scanf("%d", &n);
    printf("%d", (
	(10 < n && n <= 20) ||
	(30 <= n && n <=40) ||
	(50 <= n && n < 60) 
	));
    return 0;
}