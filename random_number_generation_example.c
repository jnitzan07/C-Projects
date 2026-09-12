#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utilities.h"

#define ARR_SIZE 100

int main() {
    double num_list[ARR_SIZE];
    double min_val = 22.53;
    double max_val = 2776.3;

    srand(time(NULL));

    printf("### generating an array of size %d ###\n", ARR_SIZE);
    fill_random(num_list, ARR_SIZE, min_val, max_val);
    print_arr_and_min_max(num_list, ARR_SIZE);
    printf("### sorting the array ###\n");
    sort_arr(num_list, ARR_SIZE);
    print_arr_and_min_max(num_list, ARR_SIZE);

    return 0;
}