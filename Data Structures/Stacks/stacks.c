#include <stdio.h>
#include <stdlib.h>

#include "stacks.h"

int get_index(Node *head, int index, Node* node_at_index) {
    // nah fam this is messy. you're taking a Node* parameter (node_at_index), and you want to **return** the node at index.
    // so let me translate to you what you're doing
    // in: integer, representing address of a node
    // set: integer = new value <-- but this doesn't change the value that the caller has.
    // in other words, if I am a caller:
    // Node* head;
    // push_node(head, my_node)
    // Node* index_0 = 0
    // get_index(head, 0, index_0)
    // what happens is inside get_index I get 0 passed in, set it to some memory address, but it doesn't change the value at my calling function.
    // this is just like if I have:
    // void make_sum(int a, int b, int sum) { sum = a + b; }
    // setting the sum INSIDE the function does nothing when I call it from the outside
    // int sum = 0; make_sum(7, 8, sum); print(sum); // sum is still 0!
    // when you want to set the value of a Node* inside your function, you need to pass in a Node**. See below, what you did with "head" in push_node.

    // but besides all that, you could just have:
    // Node* get_index(Node* head, int index) {
    //   for (; head != null && index > 0; --index) { head = head->next; } // this doesn't change "head" outside of this function! same as the int in make_sum
    //   return head; // this will just return null if the index is too big
    // }
    Node *pointer = head;

    for (pointer = head; index > 0; index--) {
        pointer = pointer -> next;
        if (pointer == NULL) {
            printf("\nIndex is greater then stack length!");
            return 0;
        }
    }

    node_at_index = pointer;
    return 1;
}

int push_node(Node **head, double new_val) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node -> value = new_val;
    new_node -> next = *head;
    *head = new_node;
    return 1;
}

int insert_node(Node **head, int index, double new_val) {
    Node *pointer;
    int valid_index;

    if (index == 0) {
        pointer = *head;
        valid_index = 1;
    } else {
        valid_index = get_index(*head, index - 1, pointer);
    }

    if (!valid_index) {
        return 0;
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node -> value = new_val;
    new_node -> next = (index == 0) ? *head: pointer -> next;

    if (index == 0) {
        *head = new_node;
    } else {
        pointer -> next = new_node;
    }

    return 1;
}

int pop_node(Node **head) {
    if (*head == NULL) {
        return 0;
    }

    Node *pointer = *head;
    *head = pointer -> next;
    free(pointer);
    return 1;
}

int remove_node(Node **head, int index) {
    Node* pointer;
    int valid_index;

    if (index == 0) {
        pointer = *head;
        valid_index = 1;
    } else {
        valid_index = get_index(*head, index - 1, pointer);
    }

    if (!valid_index) {
        return 0;
    }

    Node *temp = pointer -> next;

    pointer -> next = temp -> next;
    free(temp);
    return 1;
}

int set_value_at_index(Node *head, int index, double new_value) {
    Node *pointer = head;
    int valid_index = get_index(head, index, pointer);

    if (!valid_index) {
        return 0;
    }

    pointer -> value = new_value;
    return 1;
}

int swap_nodes(Node **head, int i, int j) {

    if ((i == j || j == 0) && (i > 0 && j > 0)) {
        return 0;
    }

    //5 pointers, 2 nodes before i and j, nodes i and j, and the node after j
    //if i is 0 then pointer_i is the head of the stack

    Node *pointer_i = NULL;
    Node *pointer_j = NULL;

    if (i == 0) {
        pointer_i = *head;
    } else {
        get_index(*head, i - 1, pointer_i);
    }
    get_index(*head, j - 1, pointer_j);

    //if i is 0 then the node i is the head of the stack
    Node *node_i = i > 0 ? pointer_i -> next: *head;
    Node *node_j = pointer_j -> next;

    Node *after_j = node_j -> next;

    if (i != 0) {
        pointer_i -> next = node_j;
    } else {
        *head = node_j;
    }

    pointer_j -> next = node_i;
    node_j -> next = node_i -> next;
    node_i -> next = after_j;

    return 1;
}

int print_stack(Node *head) {
    if (head == NULL) {
        printf("\nStack is empty!");
        return 0;
    }

    Node *pointer = head;

    //called once to fix arrow (->) formatting and such
    printf("%lf", pointer -> value);
    pointer = pointer -> next;

    while (pointer != NULL) {
        printf(" <- %lf", pointer -> value);
        pointer = pointer -> next;
    }

    return 1;
}




