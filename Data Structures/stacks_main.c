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
            get_next_action(&user_input);

            if (user_input == 0) {
                //adds a new head node
                get_new_value(&new_val);
                push_node(&stack, new_val);

        } else if (user_input == 1) {
            //deletes the head value
            pop_node(&stack);

        } else if (user_input == 2) {
            //prints all the vals
            print_stack(&stack);

        } else if (user_input == 3) {
            //gets the value of a specific index
            get_index_input(&index);
            get_index(&stack, index);

        } else if (user_input == 9) {
            running = false;
        }
    }

    return 0;
}
