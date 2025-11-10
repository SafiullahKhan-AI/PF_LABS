#include <stdio.h>

int main() {
   	int num;  
    int even = 0, odd = 0;

    printf("Enter the electricity meter reading: ");
    scanf("%d", &num);

    if (num < 0) {
        num = -num; 
    }

    while (num > 0) {
        int digit = num % 10; 
        if (digit % 2 == 0) {
            even++;
        } else {
            odd++;
        }
        num /= 10;
    }

    printf("Even digits: %d\n", even);
    printf("Odd digits: %d\n", odd);

    return 0;
}

