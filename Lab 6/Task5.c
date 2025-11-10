#include <stdio.h>

int main() {
    int n;
    unsigned long long factorial = 1; 

    printf("Enter a number u want factorial of : ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
    	int i;
        for ( i = 1; i <= n; i++) {
            factorial *= i; 
        }
        printf("Factorial of %d is %llu\n", n, factorial);
    }

    return 0;
}

