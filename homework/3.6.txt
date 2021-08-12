#include <stdio.h>
#define DAY 86400
#define HOUR 3600
#define MINUTE 60

int main() {
    long int seconds;
    scanf("%ld", &seconds);
    int days = seconds / DAY;
    seconds -= DAY * days;
    int hours = seconds / HOUR;
    seconds -= HOUR * hours;
    int minutes = seconds / MINUTE;
    seconds -= MINUTE * minutes;
    printf("%dd %d:%d:%ld", days, hours, minutes, seconds);
    return 0;
}