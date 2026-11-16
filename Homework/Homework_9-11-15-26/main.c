#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_arr(int arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        printf("Index: %d, Value: %d\n", i, arr[i]);
    }
}

void gen_random_arr(int *arr, int arr_size, int min_val, int max_val) {
    srand(time(NULL));
    for (int i = 0; i < arr_size; i++) {
        arr[i] = rand() % (max_val - min_val + 1) + min_val;
    }
}

int remove_elements_below_val(int *arr, int arr_size, int min_val) {
    int temp_index = 0;
    while (temp_index < arr_size) {
        if (arr[temp_index] < min_val) {
            for (int j = temp_index; j < arr_size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            arr_size--;
        } else {
            temp_index++;
        }
    }
    return (arr_size);
}

void swap_halves(int *arr, int arr_size) {
    int half = arr_size / 2;
    for (int i = 0; i < half; i++) {
        int temp = arr[i];
        arr[i] = arr[i + half];
        arr[i + half] = temp;
    }
}

void sort_arr(int *arr, int arr_size) {
    for (int i = 0; i < arr_size - 1; i++) {
        for (int j = 0; j < arr_size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binary_search(int *arr, int arr_size, int target) {
    int low = 0;
    int high = arr_size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int size_arr = 10;
    int min_val = 60;   // 5 ft in inches
    int max_val = 84;   // 7 ft in inches
    int arr[size_arr];
    int target;

    gen_random_arr(arr, size_arr, min_val, max_val);
    sort_arr(arr, size_arr);

    printf("Sorted student heights (inches):\n");
    print_arr(arr, size_arr);

    printf("\nEnter a height of interest (inches): ");
    fflush(stdout);
    scanf("%d", &target);

    int result = binary_search(arr, size_arr, target);

    if (result != -1) {
        printf("Height %d found at index %d\n", target, result);
    } else {
        printf("Height %d not found\n", target);
    }

    return 0;
}