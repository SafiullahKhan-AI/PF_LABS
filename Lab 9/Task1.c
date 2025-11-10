#include <stdio.h>
void input(int arr[]) {
    int i;
    for (i = 0; i < 7; i++) {
        printf("Enter Total Number of Patients on Day %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

float averagePatients(int arr[]) {
    int i; 
	float sum = 0;
    for (i = 0; i < 7; i++) {
        sum += arr[i];
    }
    return sum / 7;
}

void busyDay(int arr[]) {
    int max = arr[0], min = arr[0];
    int busyDay = 1, slowDay = 1;
    int i;

    for (i = 1; i < 7; i++) {
        if (arr[i] > max) {
            max = arr[i];
            busyDay = i + 1;
        }
        if (arr[i] < min) {
            min = arr[i];
            slowDay = i + 1;
        }
    }

    printf("Busiest Day: Day %d (%d Patients)\n", busyDay, max);
    printf("Slowest Day: Day %d (%d Patients)\n", slowDay, min);
}

int main() {
    int arr[7];
    input(arr);
    float avg = averagePatients(arr);
    printf("\nAverage Patients per Day: %.2f\n", avg);
    busyDay(arr);
    return 0;
}

