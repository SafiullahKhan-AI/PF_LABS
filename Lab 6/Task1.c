#include <stdio.h>

int main() {
    int pin, sum = 0, digit;

    printf("Enter a 4-digit PIN: ");
    scanf("%d", &pin);
    
    while (pin > 0) {
        digit = pin % 10;   
        sum += digit;    
        pin /= 10;        
    }

    if (sum > 10)
        printf("Strong PIN (Sum = %d)\n", sum);
    else
        printf("Weak PIN (Sum = %d)\n", sum);

    return 0;
}

