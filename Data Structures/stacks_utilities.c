#include <stdio.h>

#include "stacks_utilities.h"

void get_new_value(int* new_val) {
    printf("%s", "\nEnter the value of the item (int) to add: ");
    scanf("%d", new_val);
}

void get_next_action(int* user_input) {
    printf("%s", "\nWould you like to add, remove, print all items, or view a specific item (9 to exit) (0/1/2/3)?: ");
    scanf("%d", user_input);
}

void get_index_input(int* index) {
    printf("%s", "\nEnter the index of the item to view (0 is the head item): ");
    scanf("%d", index);
}