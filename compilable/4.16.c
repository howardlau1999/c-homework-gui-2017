#include <stdio.h>

int main() {
    int i = 10;
    while(i--) {
		int n;
		scanf("%d", &n);
		switch(n) {
			case 1:case 8:case 21:case 22:
			printf("A");break;
			case 6:case 13:case 17:case 25:
			printf("B");break;
			case 5:case 10:case 18:case 26:
			printf("C");break;
			case 2:case 11:case 15:case 23:
			printf("D");break;
			case 7:case 9:case 19:case 28:case 30:
			printf("E");break;
			case 3:case 14:case 16:case 24:case 29:
			printf("F");break;
			case 4:case 12:case 20:case 27:
			printf("G");
			break;

		}
	}
    return 0;
}