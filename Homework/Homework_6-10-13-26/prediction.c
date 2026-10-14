#include <stdio.h>
#include "prediction.h"

#include <stdlib.h>


int get_bday_sum() {
    int day, month, year;
    printf("\nEnter the year you were born: ");
    scanf("%d", &year);
    printf("\nEnter the month you were born (1-12): ");
    scanf("%d", &month);
    printf("\nEnter the day you were born: ");
    scanf("%d", &day);
    return (day + month + year);
};

int seed_random(int seed) {
    srand(seed);
};

int gen_card_val() {
    return (rand() % 13 + 1);
};

int check_rules(int sum, int face_val) {
    switch ((sum + face_val) % 2) {
        case 0:
            (sum % 2 == 0) ? printf("The one is already around"): printf("Very hard");
            break;
        case 1:
            (sum % 2 == 0) ? printf("Late spring"): printf("The one will appear soon");
            break;
        default:
            break;
    }
};
