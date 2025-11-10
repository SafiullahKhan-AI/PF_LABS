#include <stdio.h>
#include <math.h>

int Prime(int num) {
    if (num <= 1)
        return 0;
    if (num == 2)
        return 1; 

    int i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return 0; 
    }
    return 1;
}

int main() {
    int n;

    printf("Enter a student ID (integer): ");
    scanf("%d", &n);

    if (Prime(n))
        printf("Student ID %d is VALID (Prime number).\n", n);
    else
        printf("Student ID %d is INVALID (Not Prime number)\n", n);

    printf("Prime numbers from 1 to %d:\n", n);
    int i;
	for ( i = 2; i <= n; i++) {
        if (Prime(i))
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}

