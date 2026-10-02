#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gen_year() {
    return (rand() + 1);
}

int is_leap_year(int year) {
    int leap_year = year;

    if ((year % 400 == 0)) {leap_year = 1;}
    if ((year % 4 == 0)) {leap_year = 1;}
    if ((year % 100 == 0)) {leap_year = 0;}

    return leap_year;
}


int main() {
    srand(time(NULL));

    int year = gen_year();
    int leap_year = is_leap_year(year);

    if (leap_year) {printf("%d is a leap year!", year);}
    else printf("%d is not a leap year!", year);

    return 1;
}

