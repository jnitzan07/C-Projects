
#ifndef EE200_STACKS_H
#define EE200_STACKS_H

typedef struct Node {
    double value;
    struct Node *next;
} Node;

int push_node(Node **head, double new_val);
int insert_node(Node **head, int index, double new_val);
int pop_node(Node **head);
int remove_node(Node **head, int index);
Node* get_index(Node *head, int index);
int swap_nodes(Node **head, int i, int j);
int set_value_at_index(Node *head, int index, double value);
int print_stack(Node *head);

#endif //EE200_STACKS_H
