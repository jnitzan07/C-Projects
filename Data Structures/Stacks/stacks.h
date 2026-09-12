
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

// passing in **Node means "the address of the address of a node", which allows you to change the value of that address of the address
// for example, I have a "Node* head" in my main(). That's the address of a node (the head node). If I pass that address to your function,
// you can walk my stack. BUT you wouldn't be able to tell me "I'm changing what your head points to".
// this is a lot like if you have a function say do_10x(int value), and you want to give me back 10*value.
// the most common way to do that would be with the return value, e.g.:
// int do_10X(int value) { return 10*value; }
// BUT maybe you want it to be a void for some reason, or return true/false (like "success"). so then you want to get
// not just the value itself, but the *address* of the value, so you can change it. e.g.:
// void do_10X(int* value_addr) { int value = *value_addr; *value_addr = value * 10; } // this takes the value stored at value_addr and stores it *10 at the same address

// for your functions, get_index and print_stack just need to walk the stack, so all you need is the head - you're not going to change it
// but push_node and pop_node will actually *change* the head of the stack. so if I just pass the head, you can't change it (it's like an int).
// you need the *address of where I'm storing the head*, so you can change it directly (hence Node** head_addr), OR you need to return the new head:
// Node* push_node(Node* head, int new_val) // returns the new head
// Node* pop_node(Node* head) // returns the new head

// at this stage of your work, either option would be fine -- but note that the coding best practice is that the malloc() and free() happen in the same place
// i.e. if you are going to do the malloc() in push_node(), then you should do the free() in pop_node.
// if you look at a single int value in each node, that's fine... but what if you had 17 different values in the node?
// the clean concept is for push_node to take Node** head, Node* new_node, and for pop_node to take Node** head, and return Node* the node that was popped.
// that way the calling code code malloc() the node, and free() the node it asked you to remove

// make it good, and add a swap_nodes(int i, int j) -- that switches the location of node i and node j

void push_node(Node **head, int new_val);
void pop_node(Node **head);
void get_index(Node **head, int index);
void print_stack(Node **head);
void swap_nodes(Node **head, int i, int j);

#endif //EE200_STACKS_H
