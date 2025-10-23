#include <stdio.h>
int main() {
    int record[7];
    int i;
    for(i = 0; i < 7; i++) {
        printf("Enter the temperature of Day %d: ", i + 1);
        scanf("%d", &record[i]);
    }
    int highest = record[0];
    int lowest = record[0];
    for(i = 1; i < 7; i++) {
        if (record[i] > highest) {
            highest = record[i];
        }
        if (record[i] < lowest) {
            lowest = record[i];
        }
    }
    printf("Hottest day Temp: %d\n", highest);
    printf("Coldest day Temp: %d\n", lowest);
    return 0;
}

