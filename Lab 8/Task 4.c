#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int rows, columns,i,j;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &columns);

    int arr[rows][columns];
    int totalempty = 0, max = 0, rowmax = 0;
    srand(time(0));

    printf("\nCinema Hall Seating (0 = Empty, 1 = Occupied):\n");

    for ( i = 0; i < rows; i++) {
        int rowempty = 0;
        for ( j = 0; j < columns; j++) {
            arr[i][j] = rand() % 2;
            printf("%d ", arr[i][j]);

            if (arr[i][j] == 0) {
                totalempty++;
                rowempty++;
            }
        }
        printf("\n");
        
        if (rowempty > max) {
            max = rowempty;
            rowmax = i + 1;
        }
    }
    
    printf("\nTotal Available Seats: %d\n", totalempty);
    printf("Row with Most Empty Seats: Row %d (%d empty seats)\n", rowmax, max);

    return 0;
}

