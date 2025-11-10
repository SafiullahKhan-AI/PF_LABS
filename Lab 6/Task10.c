#include <stdio.h>

int main() {
    int n;
    printf("Enter the total number of rows for the Diamond: ");
    scanf("%d", &n);

    int upperRows = n / 2 + n % 2; 
    int lowerRows = n / 2;        

    // Upper half
    int i,j,k;
    for ( i = 1; i <= upperRows; i++) {
        for ( j = 1; j <= upperRows - i; j++)
            printf(" ");
        for ( k = 1; k <= 2*i - 1; k++) {
            if (k == 1 || k == 2*i - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    // Lower half
    for (i = lowerRows; i >= 1; i--) {
        for ( j = 1; j <= upperRows - i; j++)
            printf(" ");
        for (
		 k = 1; k <= 2*i - 1; k++) {
            if (k == 1 || k == 2*i - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}

