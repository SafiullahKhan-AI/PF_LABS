#include <stdio.h>
int main() {
    int n, i, j;
    printf("Enter size of the square board (N x N): ");
    scanf("%d", &n);
    int board[n][n];
    printf("\nEnter the elements of the board:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &board[i][j]);
        }
    }
    printf("\nOriginally the Board Looks:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d ", board[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            int temp = board[i][j];
            board[i][j] = board[j][i];
            board[j][i] = temp;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n / 2; j++) {
            int temp = board[i][j];
            board[i][j] = board[i][n - j - 1];
            board[i][n - j - 1] = temp;
        }
    }
    printf("\nAfter Rotation(90 degree Clockwise) the Board:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}

