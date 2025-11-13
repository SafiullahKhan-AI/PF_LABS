#include <stdlib.h>

int* transformArray(int* arr, int len, int* returnSize) {
    int i, j;
    *returnSize = len;                  

    int* result = (int*)malloc(len * sizeof(int));

    for(i = 0; i < len; i++) {
        if(arr[i] % 2 == 0) {
            result[i] = 0;
        } else {
            result[i] = 1;
        }
    }

    for(i = 0; i < len - 1; i++) {
        for(j = 0; j < len - i - 1; j++) {
            if(result[j] > result[j + 1]) {
                int temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }

    return result;  
}

