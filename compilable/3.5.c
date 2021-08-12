 double celsiusToFahrenheit(double celsius) {
    return 9.0/5.0*celsius+32.0;

} 
#include <stdio.h>

int main() {
	double celsius;
	scanf("%lf", &celsius);
	double fahrenheit = celsiusToFahrenheit(celsius);
	printf("%lf", fahrenheit);
}