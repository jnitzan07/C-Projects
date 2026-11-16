#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gen_nums(int *arr, int length, int min, int max) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        arr[i] = (rand() % (max - min + 1)) + min;
    }
}

void find_even(int arr[], int *even_nums, int length) {
    for (int i = 0; i < length; i++) {
        if (arr[i] % 2 == 0) {
            even_nums[i] = arr[i];
        } else {
            even_nums[i] = -1;
        }
    }
}

void print_evens(int evens[], int length) {
    printf("Index, Value\n");
    for (int i = 0; i < length; i++) {
        if (evens[i] != -1) {
            printf("%d, %d\n", i, evens[i]);
        }
    }
}

void gen_print_evens() {
    int arr_len = 10;
    int max = 100;

    int arr[arr_len];
    gen_nums(arr, arr_len, 0, max);

    int even_nums[arr_len];
    find_even(arr, even_nums, arr_len);

    print_evens(even_nums, arr_len);
}

void reverse_nums(int *reversed, int arr[], int length) {
    for (int i = 0; i < length; i++) {
        reversed[i] = arr[length - i - 1];
    }
}

void print_arr(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        if (i > 0) {
            printf(", ");
        }
        if (arr[i] != -1) {
            printf("%d", arr[i]);
        }
    }
}

void gen_reverse_array() {
    int arr_len = 10;
    int max = 99;

    int arr[arr_len];
    gen_nums(arr, arr_len, 0, max);

    int reversed_nums[arr_len];
    reverse_nums(reversed_nums, arr, arr_len);

    print_arr(arr, arr_len);
    printf("\n");
    print_arr(reversed_nums, arr_len);
}

void get_string(char *input) {
    scanf_s("%s", input);
}

void combine_strings(char s1[], char s2[], char* combined, int s1_size, int s2_size) {
    int count = 0;
    for (int i = 0; i < s1_size; i++) {
        if (s1[i] == *"") {
            break;
        }
        combined[count] = s1[i];
        count++;
    }

    for (int i = 0; i < s2_size; i++) {
        if (s2[i] == *"") {
            break;
        }
        combined[count] = s2[i];
        count++;
    }
}

void print_string(char* s, int size) {
    for (int i = 0; i < size; i++) {
        if (s[i] == *"") {
            break;
        }
        printf("%c", s[i]);
    }
}

void get_combine_strings() {
    int max_str_size = 50;

    char s1[max_str_size];
    char s2[max_str_size];

    printf("Enter a string: \n");

    get_string(s1);
    int s1_size = max_str_size;

    printf("\nEnter a string: \n");

    get_string(s2);
    int s2_size = 50;

    char* s3 = malloc(s1_size + s2_size);
    combine_strings(s1, s2, s3, s1_size, s2_size);

    printf("\n");
    print_string(s1, s1_size);
    printf("\n");
    print_string(s2, s2_size);
    printf("\n");
    print_string(s3, s1_size + s2_size);
}

int main() {
    printf("Generating and printing evens...\n");
    gen_print_evens();

    printf("\nGenerating and reversing away...\n");
    gen_reverse_array();

    printf("\n\nCombining 2 inputted strings...\n");
    get_combine_strings();
    return 0;
}