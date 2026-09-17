#include <stdio.h>

#include "stacks_utilities.h"

double get_new_value() {
    double ret_val;
    printf("%s", "\nEnter the value of the item to add: ");
    scanf("%lf", &ret_val);
    return ret_val;
}

int get_next_action() {
    int ret_val;
    printf("%s", "\nWould you like to: \nAdd an item (0), \nInsert an item (1), \nRemove a specific item (2), \nRemove the head item (3), \nPrint all items (4), \nView a specific index (5), \nSwap 2 items (6), \nChange a item (7), \nExit (9)\nAction: ");
    scanf("%d", &ret_val);
    return ret_val;
}

int get_index_input() {
    int ret_val;
    printf("%s", "\nEnter the index (0 is the head item): ");
    scanf("%d", &ret_val);
    return ret_val;
}

void change_item_get_index_input(int* index, double* new_value) {
    printf("%s", "\nEnter the index of the item to change (0 is the head item): ");
    scanf("%d", index);
    printf("%s", "\nEnter the new value of the item (0 is the head item): ");
    scanf("%lf", new_value);
}

void get_indexes_to_swap(int* i, int* j) {
    printf("%s", "\nEnter the first index to swap: ");
    scanf("%d", i);
    printf("%s", "\nEnter the second index to swap: ");
    scanf("%d", j);
}