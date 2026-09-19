#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    //math or operations
    *returnSize = 2;
    int *return_nums = malloc(sizeof(int) * *returnSize);
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                return_nums[0] = i;
                return_nums[1] = j;
                return(return_nums);
            }
        }
    }
    return(NULL);
}

int main() {
    int numsSize = 7;
    int nums[7] = {1, 2, 3, 4, 5, 6, 7};
    int *returnSize;
    int target = 5;

    int *return_nums = twoSum(nums, numsSize, target, returnSize);
    return 1;
}