#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stacks.h"
#include "stacks_utilities.h"


int main() {
    Node *stack = NULL;

    int user_input;
    int index;
    double new_val;

    bool running = true;

    //quick question. i've been using scanf instead of scanf_s, which can give issues with buffer overflows. However, our stack is only scanning integers, meaning it should be fineeee?



    while (running) {
        user_input = get_next_action();

        switch (user_input) {
            case 0:
                //adds a new head node
                new_val = get_new_value();
                push_node(&stack, new_val);
                break;
            case 1:
                //deletes the head value
                pop_node(&stack);
                break;
            case 2:
                //prints all the vals
                print_stack(stack);
                break;
            case 3:
                //gets the value of a specific index
                Node* pointer = get_index(stack, view_item_get_index_input());
                printf("Value: %lf", pointer -> value);
                break;
            case 4:
                int i;
                int j;
                get_indexes_to_swap(&i, &j);
                swap_nodes(&stack, i, j);
                break;
            case 5:
                //changes the value of a specific index
                change_item_get_index_input(&index, &new_val);
                set_value_at_index(stack, index, new_val);
                break;
            case 9:
                running = false;
                break;
            default:
                break;
        }

    }
    return 0;
}
