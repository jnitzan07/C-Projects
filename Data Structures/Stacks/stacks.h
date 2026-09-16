
#ifndef EE200_STACKS_H
#define EE200_STACKS_H

//i believe typedef is to define "Node" as a type we can pass into our functions parameters
typedef struct Node {
    double value;
    struct Node *next;
} Node;

void push_node(Node **head, double new_val);
void pop_node(Node **head);
Node* get_index(Node *head, int index);
void print_stack(Node *head);
void swap_nodes(Node **head, int i, int j);
void set_value_at_index(Node *head, int index, double value);

#endif //EE200_STACKS_H
