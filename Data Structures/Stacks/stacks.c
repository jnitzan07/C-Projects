#include <stdio.h>
#include <stdlib.h>

#include "stacks.h"

void push_node(Node **head, int new_val) {
    //adds a value (new head)
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = new_val;
    new_node->next = *head;
    *head = new_node;
}


void pop_node(Node **head) {
    if (head == NULL) {
        printf("\nStack is empty!");
        return;
    }

    struct Node *pointer = *head;
    *head = pointer -> next;
    free(pointer);
}

// this should probably return something :)
// yuh-huh bc it's getting a integer that we use :). no need to change the variable directly in this case
int get_index(Node *head, int index) {
    //prints the value at a certain index
    Node *pointer = head;

    // stylistically this isn't the nicest way imo. I would do a for(pointer=head; index>0; index--) { if (pointer == NULL) break; } and then return pointer
    for (pointer = head; index > 0; index--) {
        pointer = pointer -> next;
        if (pointer == NULL) {
            break;
        }
    }

    if  (pointer != NULL) {
        return pointer -> value;
    }

    printf("\nIndex is greater then stack length!");
    return -0;
}


//took your idea of using get_index. After all, changing the value at an index would be an eventual function, so i might as well add it now and employ it in swapping the items
void set_value_at_index(Node *head, int index, int new_value) {
    //sets the value at a index
    Node *pointer = head;

    for (pointer = head; index > 0; index--) {
        pointer = pointer -> next;
        if (pointer == NULL) {
            printf("\nIndex is greater then stack length!");
            return;
        }
    }

    pointer -> value = new_value;
}

void swap_nodes(Node **head, int i, int j) { // you wrote such a nice get_index... why not use it? ptr_i = get_index(i); ptr_j = get_index(j); deal with NULLs
    int temp_i = get_index(*head, i);
    int temp_j = get_index(*head, j);


    //i didn't add in null implementation technically (tho no issues with memory being overwritten should occur)
    //also yes i realize it's inefficient to run it twice. it'd be doable to make it continue after changing i until it changes j too, but that's too much effort.
    //also no speecific message set for if 1 index is valid and the other isn't. no edge case currently either.
    set_value_at_index(*head, i, temp_j);
    set_value_at_index(*head, j, temp_i);
}

/*
 * I would like more context on our pointers such as **head
 * It's a little confusing why in get_index we're using *head when our parameter is **head, would that be equivalent to doing ***head in the parameter?
 * I'd think we'd want an & to cancel out one of those *
 *
 *
 *
 */


void print_stack(Node *head) {
    if (head == NULL) {
        printf("\nStack is empty!");
        return;
    }

    Node *pointer = head;

    //basically just calling it once beforehand to fix formatting with the <-
    // nice :)
    // double nice! :):)

    // i dunno is that normal to do? or would there be a nicer way to deal with our arrow formatting?
    printf("%d", pointer -> value);
    pointer = pointer -> next;

    while (pointer != NULL) {
        printf(" <- %d", pointer -> value);
        pointer = pointer -> next;
    }
}