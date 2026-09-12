
#ifndef EE200_STACKS_H
#define EE200_STACKS_H

//i believe typedef is to define "Node" as a type we can pass into our functions parameters
typedef struct Node {
    int value;
    struct Node *next;
} Node;

/*
 *i believe **head means we're passing the memory address of the stack itself?
 *meanwhile passing Node *n or something would mean we wouldn't keep track of any changes to the nodes head?
 *i'm a little confused please explain
*/

void push_node(Node **head, int new_val);
void pop_node(Node **head);
void get_index(Node **head, int index);
void print_stack(Node **head);

#endif //EE200_STACKS_H
