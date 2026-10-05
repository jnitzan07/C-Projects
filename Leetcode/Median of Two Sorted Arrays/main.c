#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* n1, int s1, int* n2, int s2) {
    int size = s1 + s2;
    int *arr = malloc(size * sizeof(int));
    int count1 = 0, count2 = 0;
    for (int i = 0; i < size; i++) {
        if (count1 < s1 && count2 < s2) {
            arr[i] = (n1[count1] <= n2[count2]) ? n1[count1++] : n2[count2++];
        } else {
            arr[i] = (count1 < s1) ? n1[count1++] : n2[count2++];
        }
    }

    double result = 0;
    if (size % 2 != 0) {
        result = arr[size / 2];
    } else {
        int mid = size / 2;
        result = (((double) arr[mid] + arr[mid - 1]) / 2);
    }

    free(arr);
    return result;
}

int main() {
    int arr1[] = {2, 1, 4};
    int arr2[] = {5, 1, 2};
    int s1 = (sizeof(arr1) / sizeof(arr1[0]));
    int s2 = (sizeof(arr2) / sizeof(arr2[0]));

    double median = findMedianSortedArrays(arr1, s1, arr2, s2);
    printf("Median: %lf", median);
    return 1;
}