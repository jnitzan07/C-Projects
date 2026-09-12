#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_SIZE 200

double num_list[NUMBER_SIZE];

double biggest;
double smallest;

double min;
double max;

static void fill_random() {
    smallest = max;
    biggest = min;

    for (int i=0; i < NUMBER_SIZE; i++) {
        double rand_num = ((rand() / (RAND_MAX + 1.0)) * (max - min)) + min;

        num_list[i] = rand_num;

        if (num_list[i] > biggest) {
            biggest = num_list[i];
        }

        if (smallest > num_list[i]) {
            smallest = num_list[i];
        }
    }
}

static void sort_numbers() {
    double new_array[NUMBER_SIZE];
    int count = 0;

    for (int j = 0; j < NUMBER_SIZE; j++) {
        double smallest = max;
        int index = 0;
        for (int i = 0; i < NUMBER_SIZE; i++) {
            if (num_list[i] <= smallest) {
                smallest = num_list[i];
                index = i;
            }
        }
        num_list[index] = max;
        new_array[j] = smallest;
    }


    for (int i = 0; i < NUMBER_SIZE; i++) {
        num_list[i] = new_array[i];
    }
}

static void print_numbers() {
    for (int i=0; i<NUMBER_SIZE; i++) {
        printf("\n%lf", num_list[i]);
    }

    printf("\nThe smallest number generated was: %lf, and it's the 1st item of the array", smallest);
    printf("\nThe biggest number generated was: %lf, and it's the %dth item of the array", biggest, NUMBER_SIZE);
}

int main() {
    min = 22.53;
    max = 2776.3;

    srand(time(NULL));

    fill_random();
    sort_numbers();
    print_numbers();

    return 0;
}
