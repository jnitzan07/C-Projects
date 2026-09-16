#include <stdio.h>
#include <stdlib.h>

#include "stacks.h"


//changed the stack to use doubles instead of int's, literally took 5 min bc of how the code is configured


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

Node* get_index(Node *head, int index) {
    Node *pointer = head;

    // stylistically this isn't the nicest way imo. I would do a for(pointer=head; index>0; index--) { if (pointer == NULL) break; } and then return pointer
    for (pointer = head; index > 0; index--) {
        pointer = pointer -> next;
        if (pointer == NULL) {
            break;
        }
    }

    if  (pointer != NULL) {
        //this is a cast down from double to int... should at least give a compile warning if not an error
        return pointer;
    }

    printf("\nIndex is greater then stack length!");
    return pointer;
}


//took your idea of using get_index. After all, changing the value at an index would be an eventual function, so i might as well add it now and employ it in swapping the items
/* This is a good example of what I was saying above. If get_index(index) returned a Node*,
   you could call set_value(index, new_value) and it would call get_index(index)->value = new_value */
void set_value_at_index(Node *head, int index, double new_value) {
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

/* This solution is nice, but again hard-codes that the value of the nodes is integer. So you'll see when you go to make it a double,
   this code can break in subtle ways. It's much nicer to swap the nodes in terms of the pointers pointing to them / away from them,
   so you literally re-link the list to make the swap, rather than just swapping the values. Then you can change the value type and
   this code remains completely unchanged.
   Dealing with the success / fail conditions is similar to what I said about get_index(), you can return "FAIL" (0) or "SUCCESS" (1),
   if you don't make the function a void.
*/

/* Well in the case of changing it do doubles, all I had to do was change some "%d" to "%lf", some function return types, and some variable types.
 * While it is true the solution is hard-coded for the type, I don't think there's a way to make it a dynamic type all around? At least not with my current level of C.
 * Mainly bc we have to change our print statements and variable types. Elsewise I could make the functions return the pointer to a node if I wanted to and grab the value from that node.
 * It'd just take like 20 minutes of work tho :<, and I'm lazzzzzy! ;)
*/

//as for the swapping the pointers, working on it, more difficult then i expected.

void swap_nodes(Node **head, int i, int j) {
    Node *pointer_i;
    Node *pointer_j;

    if (i != 0) {
        pointer_i = get_index(*head, i - 1);
    } else {
        pointer_i = get_index(*head, i);
    }

    if (j != 0) {
        pointer_j = get_index(*head, j - 1);
    } else {
        pointer_j = *head;
    }


    //this is written out overly complex (there's 100% a easier way to do this I was too lazy to implement)
    //but basically we're changing the pointers of the nodes prior to the node at index i and j to be each other
    //then incrementing those by one (so our prior node for i's next would now go to node j).
    //then we swap the next for nodes i and j
    //this doesn't work if one of the indexes is 0, working on fixing that

    Node *temp = pointer_j -> next;
    pointer_j -> next = pointer_i -> next;
    pointer_i -> next = temp;

    pointer_i = pointer_i -> next;
    pointer_j = pointer_j -> next;

    temp = pointer_j -> next;
    pointer_j -> next = pointer_i -> next;
    pointer_i -> next = temp;
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
