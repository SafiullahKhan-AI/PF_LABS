#include <stdio.h>

int main() {
    int mark;
    int sum = 0, count = 0;
    float average;

    printf("Enter student marks one by one (Enter -1 to Stop):\n");

    while (1) {
        scanf("%d", &mark);

        if (mark == -1) {
            break;
        }

        sum += mark;
        count++;
    }

    if (count > 0) {
        average = (float)sum / count; 
        printf("Average marks = %.2f\n", average);
    } else {
        printf("No marks entered.\n");
    }
    return 0;
}

