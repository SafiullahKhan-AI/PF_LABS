#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int total = 0, min = 0;
    float average;
    int option, category;

    printf("Enter no of book categories: ");
    scanf("%d", &n);

    int *stock = malloc(n * sizeof(int));

    if (stock == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Stock for Each Category:\n");
    for (int i = 0; i < n; i++) {
        printf("Category %d: ", i+1);
        scanf("%d", &stock[i]);
    }
    for (int i = 0; i < n; i++) {
        total += stock[i];

        if (stock[i] < stock[min]){
            min = i;
        }
    }

    average = (float) total / n;

    printf("---Report---\n");
    printf("Total Stocks Entered: %d\n", total);
    printf("Average Stocks per Category: %.2f\n", average);
    printf("Lowest stock Category: %d (Stock: %d)\n", min+1, stock[min]);
    do{
    printf("Want to update stock? Type(1/0): ");
    scanf("%d", &option);
        if (option == 1){
        printf("Enter Category index for Update: ");
        scanf("%d", &category);
            if (category >= 0 && category < n+1){
                int x = category-1; 
            printf("Enter New value for Stock: ");
            scanf("%d", &stock[x]);
            printf("Stock successfully updated!\n");
            } else {
            printf("Invalid index...try again\n");
            }
        }
    } while (option);

    free(stock);
    printf("Exiting-----\n");
}
