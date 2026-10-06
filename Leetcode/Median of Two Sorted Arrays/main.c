#include <stdio.h>
#include <stdlib.h>

#include <stdlib.h>

#include <stdlib.h>

double findMedianSortedArrays(int* n1, int s1, int* n2, int s2) {
    //time complexity should be O(log(m+n))
    int max = ((s1 + s2) % 2 == 0) ? (s1 + s2) / 2 : (s1 + s2 + 1) / 2;

    int curr;
    int prev;

    int count1 = 0, count2 = 0;
    int index = 0;
    while ((count1 + count2) <= max) {
        prev = curr;
        if (count1 < s1 && count2 < s2) {
            curr = (n1[count1] <= n2[count2]) ? n1[count1++]: n2[count2++];
        } else {
            if(count1 >= s1 && count2 >= s2) {break;}
            curr = (count1 < s1) ? n1[count1++]: n2[count2++];
        }
        index++;
    }

    double result = 0;
    if ((s1 + s2) % 2 != 0) {
        result = prev;
    } else {
        result = (((double) curr + prev) / 2);
    }

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