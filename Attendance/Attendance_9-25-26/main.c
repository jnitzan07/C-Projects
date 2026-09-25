#include <stdio.h>
#include <string.h>
#include <math.h>

static void print_asterisks(int rows, int start_count, int increment, int start_spaces, int space_increment) {
    for (int i = 0; i < rows; i++) {
        int current_count = start_count + i * increment;
        int space_count = start_spaces + i * space_increment;

        if (space_count < 0 || current_count < 0) return;

        char asterisks[current_count + 1];
        char spaces[space_count + 1];

        memset(asterisks, '*', current_count);
        memset(spaces, ' ', space_count);

        asterisks[current_count] = '\0';
        spaces[space_count] = '\0';

        printf("%s%s\n", spaces, asterisks);
    }
    printf("\n");
}

int main() {

    int rows, start_count, increment, start_spaces, space_increment;

    //figure 1
    rows = 5;
    start_count = 1;
    increment = 1;
    start_spaces = 0;
    space_increment = 0;
    print_asterisks(rows, start_count, increment, start_spaces, space_increment);

    //figure 2
    rows = 5;
    start_count = 5;
    increment = -1;
    start_spaces = 0;
    space_increment = 0;
    print_asterisks(rows, start_count, increment, start_spaces, space_increment);

    //figure 3
    rows = 5;
    start_count = 5;
    increment = 0;
    start_spaces = 0;
    space_increment = 1;
    print_asterisks(rows, start_count, increment, start_spaces, space_increment);

    //figure 4
    rows = 5;
    start_count = 5;
    increment = 0;
    start_spaces = 4;
    space_increment = -1;
    print_asterisks(rows, start_count, increment, start_spaces, space_increment);

    //figure 5
    rows = 4;
    start_count = 1;
    increment = 2;
    start_spaces = 3;
    space_increment = -1;
    print_asterisks(rows, start_count, increment, start_spaces, space_increment);

}
