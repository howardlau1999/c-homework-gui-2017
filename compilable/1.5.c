float fahrenheit2celsius(float f) {
    return (f - 32.0) / 1.8;
}

#include <stdio.h>

int main()
{
	float f; // Fahrenheit degree
	scanf("%f", &f);
	float c; // Celsius degree
	c = fahrenheit2celsius(f);
	printf("%f", c);
}