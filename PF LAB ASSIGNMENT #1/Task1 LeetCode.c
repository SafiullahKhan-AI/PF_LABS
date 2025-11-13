#include <stdlib.h> 

int* runningSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;  

    int* result = (int*)malloc(numsSize * sizeof(int));
    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];  
        result[i] = sum;
    }

    return result;   
}

