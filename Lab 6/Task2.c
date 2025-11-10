#include <stdio.h>

int main() {
    int num, digit;
    int reverse = 0;

    printf("Enter ticket number: ");
    scanf("%d", &num);

    while (num > 0) {
        digit = num % 10;        
        reverse = reverse * 10 + digit;
        num /= 10;      
    }

    printf("Reversed ticket number is : %d\n", reverse);

    return 0;
}

