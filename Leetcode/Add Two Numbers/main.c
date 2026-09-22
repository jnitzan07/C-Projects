

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

//on leetcode we don't get all the listnode methods
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l3;

    //constraints is max 100 nodes
    int l1_digits[101] = {0};
    int l1_count = 1;
    while (l1 != NULL) {
        l1_digits[101 - l1_count] = l1 -> val;
        l1 = l1->next;
        l1_count++;
    }

    int l2_digits[101] = {0};
    int l2_count = 1;
    while (l2 != NULL) {
        l2_digits[101 - l2_count] = l2 -> val;
        l2 = l2->next;
        l2_count++;
    }

    //printf testing confirms getting l1 and l2 as arrays of digits works at least
    int sum_digits[101] = {0};

    int sum_count = (l1_count >= l2_count ? l1_count: l2_count);

    for (int i = 100; i >= 0; i--) {
        sum_digits[i] += l1_digits[i] + l2_digits[i];
        if (sum_digits[i] >= 10 && i != 0) {
            sum_digits[i] %= 10;
            sum_digits[i - 1] += 1;
        }
    }

    for (int j = 100 - sum_count; j <= 100; j++) {
        struct ListNode *new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
        new_node -> val = sum_digits[j];
        new_node -> next = l3;
        l3 = new_node;
    }

    printf("%d", sum_count);

    return (l3);
}

int main() {
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;

    struct ListNode* result = addTwoNumbers(l1, l2);
    return 1;
}