#include <stdio.h>
#include "sic_bo.h"

int get_user_input() {
    printf("\nGuess big [1] or small [0]:\n");

    int guess;
    scanf("%d", &guess);
    if (guess != 0 && guess != 1) {guess = -1;}

    return guess;
};

int add_dice(int d1, int d2, int d3) {
    printf("The dice are: %d, %d, and %d, which sum up to %d!", d1, d2, d3, d1 + d2 + d3);
    return d1 + d2 + d3;
};

int calculate_winner(int guess, int die_sum) {
    if (guess && die_sum > 10) {
        return 1;
    } else {
        return 0;
    }
}


