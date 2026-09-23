

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

//on leetcode we don't get all the listnode methods
struct ListNode {
    int val;
    struct ListNode *next;
};



void sum_digits(int l1_digits[101], int l2_digits[101], int sum_digits[101]) {
    for (int i = 0; i < 101; i++) {
        sum_digits[100 - i] += l1_digits[100 - i] + l2_digits[100 - i];
        if (sum_digits[100 - i] >= 10 && i != 100) {
            sum_digits[100 - i] %= 10;
            sum_digits[100 - i - 1] += 1;
        }
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    //constraints is max 100 nodes
    int l1_digits[101] = {0};
    int l1_count = 1;
    while (l1 != NULL) {
        l1_digits[101 - l1_count] = l1 -> val;
        l1 = l1 -> next;
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
    int sum_count = (l1_count >= l2_count ? l1_count: l2_count);
    int sum[101] = {0};
    sum_digits(l1_digits, l2_digits, sum);

    int count = 0;


    struct ListNode *l3 = NULL;

    for (int j = 100 - sum_count + 2; j < 101; j++) {
        struct ListNode *new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
        new_node -> val = sum[j];
        new_node -> next = l3;
        l3 = new_node;
    }

    return (l3);
}

int main() {
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;

    struct ListNode* result = addTwoNumbers(l1, l2);
    return 1;
}