#include <stdio.h>

int main() {
    int num, original, reverse = 0, digit;

    printf("Enter the library book code: ");
    scanf("%d", &num);
    original = num;  
    while (num > 0) {
        digit = num % 10;          
        reverse = reverse * 10 + digit; 
        num /= 10;                   
    }

    if (original == reverse) {
        printf("The book code %d is VALID\n", original);
    } else {
        printf("The book code %d is INVALID\n", original);
    }

    return 0;
}

