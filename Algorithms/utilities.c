#include <stdio.h>
#include <stdlib.h>

void fill_random(double* arr, int len, double min_val, double max_val) {
    for (int i=0; i < len; i++) {
        double rand_num = ((rand() / ((double)RAND_MAX)) * (max_val - min_val)) + min_val;
        arr[i] = rand_num;
    }
}

void sort_arr(double* arr, int len) {
    // in-place bubble sort. pretty inefficient but it gets the job done.
    // we'll put the smallest number of each scan in arr[j], swapping it with the number that was there
    for (int j = 0; j < len; j++) {
        // safe number to start from
        int smallest_index = len - 1;
        double smallest = arr[smallest_index];

        // we'll start the scan from index j, so we skip the numbers we've already sorted
        for (int i = j; i < len; i++) {
            if (arr[i] < smallest) {
                smallest = arr[i];
                smallest_index = i;
            }
        }

        // swap the smallest number to the start of the array, and loop
        double temp = arr[j];
        arr[j] = arr[smallest_index];
        arr[smallest_index] = temp;
    }

}

void print_arr_and_min_max(double* arr, int len) {
    int smallest_index = 0, biggest_index = 0;
    double smallest = arr[0], biggest = arr[0];

    for (int i=0; i<len; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
            smallest_index = i;
        }
        if (arr[i] > biggest) {
            biggest = arr[i];
            biggest_index = i;
        }
        printf("arr[%d]: %lf\n", i, arr[i]);
    }

    printf("The smallest number is %lf at index %d\n", smallest, smallest_index);
    printf("The largest number is %lf at index %d\n", biggest, biggest_index);
}