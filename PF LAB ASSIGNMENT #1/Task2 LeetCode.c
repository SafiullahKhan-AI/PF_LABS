#include <stdlib.h>

int* shuffle(int* arr, int len, int x, int* returnSize) {
    *returnSize = len;                      
    int* result = (int*)malloc(len * sizeof(int));

    int i, j = 0;
    int y = x;                               

    for(i = 0; i < x; i++) {
        result[j++] = arr[i];              
        result[j++] = arr[y++];             
    }

    return result;
}

