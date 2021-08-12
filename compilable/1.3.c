#include <stdio.h>

float fahrenheit2celsius(float f) {
    return (f - 32.0) / 1.8;
}

int main() {
    float f = 100.0;
    float c = fahrenheit2celsius(f);
    printf("It is %f degree Celsius.", c);
    return 0;
}
