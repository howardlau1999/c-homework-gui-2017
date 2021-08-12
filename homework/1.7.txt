#include <stdio.h>

float fahrenheit2celsius(float f) {
    return (f - 32.0) / 1.8;
}

int main() {
    float f = 80.0;
    while (f <= 100.0) {
        printf("%f\t%f\n", f, fahrenheit2celsius(f));
        f += 1.0;
    }
    return 0;
}
