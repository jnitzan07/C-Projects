#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stacks.h"
#include "stacks_utilities.h"

int push_random_int_sorted(Node **stack, int max) {
    Node *pointer = *stack;
    int r1 = rand() % max;
    int count = 0;
    Node *item = get_index(pointer, count);
    while (item != NULL && r1 >= item -> value) {
        item = get_index(pointer, count);
        count++;
    }
    insert_node(&pointer, count, r1);
}

int user_action_stack(Node *stack) {

    bool running = true;

    while (running) {
        int user_input = get_next_action();
        int index;
        double new_val;

        Node* pointer = nullptr;

        switch (user_input) {
            pointer = nullptr;
            case 0: //adds a new node at the head of the stack
                push_node(&stack, get_new_value());
                break;
            case 1: //inserts a new node at a specified index
                index = get_index_input();
                new_val = get_new_value();
                insert_node(&stack, index, new_val);
                break;
            case 2: //deletes the node at a specified index
                index = get_index_input();
                remove_node(&stack, index);
                break;
            case 3: //deletes the head node
                pop_node(&stack);
                break;
            case 4: //prints all nodes in stack
                print_stack(stack);
                break;
            case 5: //gets the value of the node at a index
                index = get_index_input();
                pointer = get_index(stack, index);
                if (pointer == NULL) {
                    printf("\nIndex is greater then stack length!");
                } else {
                    printf("Value: %lf", pointer -> value);
                }
                break;
            case 6: //swaps 2 nodes (via pointer swapping)
                int i, j;
                get_indexes_to_swap(&i, &j);
                swap_nodes(&stack, i, j);
                break;
            case 7: //changes the value of a specific index
                change_item_get_index_input(&index, &new_val);
                set_value_at_index(stack, index, new_val);
                break;
            case 9: //exit condition
                running = false;
                break;
            default: //for invalid inputs
                break;
        }
    }

    return 0;
}

int main() {
    Node *stack = nullptr;
    //user_action_stack(stack);
    for (int i = 0; i < 100; i++) {
        push_random_int_sorted(&stack, 1000);
    }
    print_stack(stack);

    return 0;
}
