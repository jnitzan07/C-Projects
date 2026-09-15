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
// yuh-huh bc it's getting a integer that we use :). no need to change the variable directly in this case
/*
This is a classic thing to think about in C (and C++, and others). basically you're defining your "API"
and need to contemplate what that does. Here for example, you can return an int, which means "the int in that node",
but then you need to deal with the case of "what if the index is out of range?", and returning -0 is not a reliable
way of communicating an error condition.
Now you have a couple of choices for how to deal with it:
A. Set the return value into a pointer that's passed in, but actually return a status code
int get_index(Node *head, int index, int* return_value) { 
   if (index out of range) return 0; // 0 = fail
   else *return_value = node->value;
   return 1; // 1 = success
}

then your caller would use if (get_index(head, 7, &value)) print(value), for example.

B. Another way to go is to return the node itself:
Node* get_index(Node* head, int index) {
   Node* ptr;
   for(ptr=head; ptr != NULL && index > 0; index--) {
      ptr = ptr->next;
   }
   return ptr; // this will return NULL if we ran out of the stack...
}

then your caller does Node* ptr = get_index(head, 7); if (ptr != NULL) print(ptr->value);

Ultimately it kind of depends on whether you envision the user of your stack wanting to get the actual Node (e.g. maybe they want
to see the next ptr) or just the value. In C we don't have object classes, so it's hard to "hide" the idea of how your stack actually
works under the covers. Whereas say in C++ or Java you could have a "Stack" class that has a "head" private member and hides all the complexity
of how a stack actually works (you could even use templating to make the value type configurable).

Anyway these are all some more advanced ideas. For now, let's change your stack to have a double value instead of int, I think it'll be more
similar to our array solution.
*/
int get_index(Node *head, int index) {
    //prints the value at a certain index
    Node *pointer = head;

    // stylistically this isn't the nicest way imo. I would do a for(pointer=head; index>0; index--) { if (pointer == NULL) break; } and then return pointer
    for (pointer = head; index > 0; index--) {
        pointer = pointer -> next;
        if (pointer == NULL) {
            break;
        }
    }

    if  (pointer != NULL) {
        return pointer -> value;
    }

    printf("\nIndex is greater then stack length!");
    return -0;
}


//took your idea of using get_index. After all, changing the value at an index would be an eventual function, so i might as well add it now and employ it in swapping the items
/* This is a good example of what I was saying above. If get_index(index) returned a Node*,
   you could call set_value(index, new_value) and it would call get_index(index)->value = new_value */
void set_value_at_index(Node *head, int index, int new_value) {
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
void swap_nodes(Node **head, int i, int j) { // you wrote such a nice get_index... why not use it? ptr_i = get_index(i); ptr_j = get_index(j); deal with NULLs
    int temp_i = get_index(*head, i);
    int temp_j = get_index(*head, j);


    //i didn't add in null implementation technically (tho no issues with memory being overwritten should occur)
    //also yes i realize it's inefficient to run it twice. it'd be doable to make it continue after changing i until it changes j too, but that's too much effort.
    //also no speecific message set for if 1 index is valid and the other isn't. no edge case currently either.
    set_value_at_index(*head, i, temp_j);
    set_value_at_index(*head, j, temp_i);
}

/*
 * I would like more context on our pointers such as **head
 * It's a little confusing why in get_index we're using *head when our parameter is **head, would that be equivalent to doing ***head in the parameter?
 * I'd think we'd want an & to cancel out one of those *
 */

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

void print_stack(Node *head) {
    if (head == NULL) {
        printf("\nStack is empty!");
        return;
    }

    Node *pointer = head;

    //basically just calling it once beforehand to fix formatting with the <-
    // nice :)
    // double nice! :):)

    // i dunno is that normal to do? or would there be a nicer way to deal with our arrow formatting?
    printf("%d", pointer -> value);
    pointer = pointer -> next;

    while (pointer != NULL) {
        printf(" <- %d", pointer -> value);
        pointer = pointer -> next;
    }
}
