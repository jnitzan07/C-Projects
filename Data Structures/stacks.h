
#ifndef EE200_STACKS_H
#define EE200_STACKS_H

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void push_node(Node **head, int new_val);
void pop_node(Node **head);
void get_index(Node **head, int index);
void print_stack(Node **head);

#endif //EE200_STACKS_H
