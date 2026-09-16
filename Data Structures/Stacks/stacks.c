#include <stdio.h>
#include <stdlib.h>

#include "stacks.h"

Node* get_index(Node *head, int index) {
    Node *pointer = head;

    for (pointer = head; index > 0; index--) {
        pointer = pointer -> next;
        if (pointer == NULL) {
            break;
        }
    }

    if  (pointer == NULL) {
        printf("\nIndex is greater then stack length!");
    }
    return pointer;
}

void push_node(Node **head, double new_val) {
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

    Node *pointer = *head;
    *head = pointer -> next;
    free(pointer);
}

void set_value_at_index(Node *head, int index, double new_value) {
    Node *pointer = head;
    get_index(head, index) -> value = new_value;
}

void swap_nodes(Node **head, int i, int j) {

    if (i == j) {
        return;
    }

    //5 pointers, 2 nodes before i and j, nodes i and j, and the node after j
    //if i is 0 then pointer_i is the head of the stack
    Node *pointer_i = i > 0 ? get_index(*head, i - 1): *head;
    Node *pointer_j = get_index(*head, j - 1);

    //if i is 0 then the node i is the head of the stack
    Node *node_i = i > 0 ? pointer_i -> next: *head;
    Node *node_j = pointer_j -> next;

    Node *after_j = node_j -> next;

    if (i > 0) {
        pointer_i -> next = node_j;
    } else {
        *head = node_j;
    }

    pointer_j -> next = node_i;
    node_j -> next = node_i -> next;
    node_i -> next = after_j;

}

void print_stack(Node *head) {
    if (head == NULL) {
        printf("\nStack is empty!");
        return;
    }

    Node *pointer = head;

    //called once to fix arrow (->) formatting and such
    printf("%lf", pointer -> value);
    pointer = pointer -> next;

    while (pointer != NULL) {
        printf(" <- %lf", pointer -> value);
        pointer = pointer -> next;
    }
}



/*
    The confusing bit is that the unary * and & operators mean different things in the declaration part of a function (or variable)
    vs the code that uses them. In the declaration part of code, * means "pointer", and & means "reference" (I haven't taught you about that yet).
    And because the compiler doesn't care about whitespace, I like to write it out this way:

    int get_index(Node* head) { return 0; } // declares get_index that takes a "pointer to Node" as a parameter (called head)
    int add_node(Node** head, int value) {...} declares add_node that takes a "pointer to a pointer to Node", so you can change what
        that pointer points to. Why? Because when you add something to the head, the value of the memory address stored in your "head"
        variable needs to change.

    When you're in the statement (not declaration) part of code, * means "value stored at this memory address", and & means "memory address of this variable".
    So e.g. I have int get_int_from_user() { int my_int; int* my_int_ptr = &my_int; scanf("%d", my_int_ptr); return my_int (or *my_int_ptr); }

    This is confusing to EVERYONE when they first learn it. The way to fix it is to learn to verbalize the words when you read it.
    int get_int_from_user() {
        int my_int; // integer variable
        int* my_int_ptr = &my_int; // integer pointer my_int_ptr contains the address of the my_int integer
        scanf("%d", my_int_ptr); // read user input into the integer pointer, i.e. into the my_int integer
        return my_int;
        ....or
        return *my_int_ptr; // return the value stored in the address my_int_ptr (which is the value of my_int)
    }

    Hopefully this makes sense. Learn to read code with these words accurately stated, and you will never go wrong.
*/




