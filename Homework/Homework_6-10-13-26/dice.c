#include <stdlib.h>

#include "dice.h"

int roll_die(int min, int max) {
    return (rand() % (max - min + 1) + min);
}

int roll_dice(int min, int max, int rolls, int *faces) {
    for (int i = 0; i < rolls; i++) {
        faces[roll_die(min, max) - 1]++;
    }
    return 1;
}