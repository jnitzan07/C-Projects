//
// Created by jnitz on 10/13/2026.
//

#include "greatest_common_divisor.h"

int get_divisors(int num, int* divisors) {
    int count = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            divisors[count++] = i;
        }
    }
    divisors[count] = -1;
    return 1;
}


int compare_divisors(int* div1, int* div2) {
    int greatest = 1;

    int c1 = 0;
    int c2 = 0;
    while (div1[c1] != -1) {
        c2 = 0;
        while (div2[c2] != -1) {
            if (div2[c2] > div1[c1]) {
                break;
            }
            if (div2[c2] == div1[c1]) {
                greatest = div2[c2];
            }
            c2++;
        }
        c1++;
    }
    return greatest;
}