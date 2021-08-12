#include <stdio.h>

int main() {
    int i = -1;
    int numbers[10];
    while (i++ < 9) {
        scanf("%d", &numbers[i]);
    }
    i = -1;
    while (i++ < 9) {
        if (numbers[i] > 0)
        printf("%d ", numbers[i]);
    }
    
    return 0;
}
