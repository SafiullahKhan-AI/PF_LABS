#include <stdio.h>
int main()
{
    float sum = 0, avg;
    int i = 0;
    float watts[24];
    for (i = 0; i < 24; i++)
    {
        printf("Enter the %d hour reading: ", i + 1);
        scanf("%f", &watts[i]);
        sum = sum + watts[i];
    }
    avg = sum / 24;
    printf("Total Sum: %f\n", sum);
    printf("Average : %f", avg);
}
