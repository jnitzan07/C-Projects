#include <stdio.h>

#include "stacks_utilities.h"

void get_new_value(int* new_val) {
    printf("%s", "\nEnter the value of the item (int) to add: ");
    scanf("%d", new_val);
}

void get_next_action(int* user_input) {
    printf("%s", "\nWould you like to add (0), remove (1), print all items (2), view a specific  (3), or swap 2 items (4) (9 to exit)?: ");
    scanf("%d", user_input);
}

void get_index_input(int* index) {
    printf("%s", "\nEnter the index of the item to view (0 is the head item): ");
    scanf("%d", index);
}

void get_indexes_to_swap(int* i, int* j) {
    printf("%s", "\nEnter the first index to swap: ");
    scanf("%d", i);
    printf("%s", "\nEnter the second index to swap: ");
    scanf("%d", j);
}