#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stacks.h"
#include "stacks_utilities.h"


int main() {
    Node *stack = NULL;

    int user_input;
    int index;
    int new_val;

    bool running = true;

    while (running) {
        user_input = get_next_action();

        if (user_input == 0) {
            //adds a new head node
            new_val = get_new_value();
            push_node(&stack, new_val);

        } else if (user_input == 1) {
            //deletes the head value
            pop_node(&stack);

        } else if (user_input == 2) {
            //prints all the vals
            print_stack(stack);

        } else if (user_input == 3) {
            //gets the value of a specific index
            printf("Value: %d", get_index(stack, view_item_get_index_input()));

        } else if (user_input == 4) {
            int i;
            int j;
            get_indexes_to_swap(&i, &j);
            swap_nodes(&stack, i, j);

        } else if (user_input == 5) {
            //changes the value of a specific index
            change_item_get_index_input(&index, &new_val);
            set_value_at_index(stack, index, new_val);

        } else if (user_input == 9) {
            running = false;
        }
    }
    return 0;
}
