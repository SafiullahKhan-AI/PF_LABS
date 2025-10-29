#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int x=8,max=255;
    int original_matrix[x][x];
    int bright_matrix[x][x];
    int i,j;
    srand(time(NULL));
    for (i = 0; i < x; i++) {
        for (j=0; j<x; j++) {
            original_matrix[i][j] = rand() % 256;
            bright_matrix[i][j] = original_matrix[i][j] + 20;

            if (bright_matrix[i][j] > max)
                bright_matrix[i][j] = max;
        }
    }
    printf("Original Matrix of (8x8):\n");
    for (i = 0; i < x; i++) {
        for (j = 0; j < x; j++) {
            printf("%5d ", original_matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nBrightened Matrix of (8x8):\n");
    for (i = 0; i < x; i++) {
        for (j = 0; j < x; j++) {
            printf("%5d ", bright_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
