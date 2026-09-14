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
void get_index(Node *head, int index) {
    //prints the value at a certain index
    int count = 0;
    Node *pointer = head;

    // stylistically this isn't the nicest way imo. I would do a for(pointer=head; index>0; index--) { if (pointer == NULL) break; } and then return pointer
    while (pointer != NULL) {
        if (count == index) {
            printf("Value: %d", pointer -> value);
            return;
        }
        pointer = pointer -> next;
        count++;
    }

    printf("\nIndex is greater then stack length!");
}

void swap_nodes(Node **head, int i, int j) { // you wrote such a nice get_index... why not use it? ptr_i = get_index(i); ptr_j = get_index(j); deal with NULLs
    int count = 0;
    Node *pointer = *head;
    Node *temp_pointer;

    int temp_val;

    while (count != i) {
        if (pointer = NULL) {
            printf("invalid index");
            return;
        }
        pointer = pointer -> next;
        count++;
    }

    temp_pointer = pointer;
    temp_val = pointer -> value;

    pointer = pointer -> next;
    count++;

    while (count != j) {
        if (pointer = NULL) {
            printf("invalid index");
            return;
        }

        pointer = pointer -> next;
        count++;
    }

    temp_pointer -> value = pointer -> value;
    pointer -> value = temp_val;
}


void print_stack(Node *head) {
    if (head == NULL) {
        printf("\nStack is empty!");
        return;
    }

    Node *pointer = head;

    //basically just calling it once beforehand to fix formatting with the <-
    // nice :)
    printf("%d", pointer -> value);
    pointer = pointer -> next;

    while (pointer != NULL) {
        printf(" <- %d", pointer -> value);
        pointer = pointer -> next;
    }
}