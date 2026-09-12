#include <stdio.h>
#include <stdlib.h>
#define MAX_COLS 10000;
#define MAX_ROWS 10000;

struct Node {
    int value;
    struct Node *next;
};

struct Node *head = NULL;

int main() {
    int userinput;
    int index;
    int new_val;

    bool running = true;

    while (running) {
        printf("%s", "\nWould you like to add, remove, print, or change an item (9 to exit) (0/1/2/3)?: ");
        scanf("%d", &userinput);

        if (userinput == 0) {
            //adds a value (new head)
            printf("%s", "\nEnter the value of the item to add: ");
            scanf("%d", &new_val);
            struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->value = new_val;
            new_node->next = head;
            head = new_node;


        } else if (userinput == 1) {
            //deletes the head value

            if (head == NULL) {
                printf("\nStack is empty!");
                continue;
            }

            struct Node *pointer = head;
            head = pointer -> next;
            free(pointer);

        } else if (userinput == 2) {
            //prints all the vals

            if (head == NULL) {
                printf("\nStack is empty!");
                continue;
            }

            struct Node *pointer = head;
            while (pointer != NULL) {
                printf(", %d", pointer -> value);
                pointer = pointer -> next;
            }

        } else if (userinput == 3) {
            //change a value
            printf("%s", "\nEnter the index of the item to change: ");
            scanf("%d", &index);
            printf("%s", "\nEnter the new value of the item: ");
            scanf("%d", &new_val);


        } else if (userinput == 9) {
            running = false;
        }
    }
    printf("%s", "\n");
    return 0;
}