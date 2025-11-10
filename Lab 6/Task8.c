#include <stdio.h>
unsigned long long factorial(int num) {
    unsigned long long fact = 1;
    int i;
    for (i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n;
    printf("Enter the number for Catalan numbers: ");
    scanf("%d", &n);

    printf("First %d Catalan numbers are:\n", n);
    int i;
    for ( i = 0; i < n; i++) {
        unsigned long long catalan = factorial(2*i) / (factorial(i+1) * factorial(i));
        printf("%llu ", catalan);
    }
    printf("\n");

    return 0;
}

