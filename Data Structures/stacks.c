#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stacks.h"

// move this into a .h file, and add function declarations for push_node(), pop_node(), get_index(), and print_stack()
// change your main to call the functions from your .h file instead of implementing inline


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


void get_index(Node **head, int index) {
    //prints the value at a certain index
    int count = 0;
    Node *pointer = *head;
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


void print_stack(Node **head) {
    if (head == NULL) {
        printf("\nStack is empty!");
        return;
    }

    Node *pointer = *head;

    //basically just calling it once beforehand to fix formatting with the <-
    printf("%d", pointer -> value);
    pointer = pointer -> next;

    while (pointer != NULL) {
        printf(" <- %d", pointer -> value);
        pointer = pointer -> next;
    }
}