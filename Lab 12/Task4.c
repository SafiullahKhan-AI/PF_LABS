#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int total = 0, h_index = 0;
    printf("Enter the no of movie categories: ");
    scanf("%d", &n);
    int *ratings = malloc(n * sizeof(int));

    if (ratings == NULL) {
        printf("Memory Allocation fail\n");
        return 1;
    }

    printf("Enter rating of Each category:\n");
    for (int i = 0; i < n; i++) {
        printf("Category %d rating count: ", i + 1);
        scanf("%d", &ratings[i]);
    }

    int h_rating = ratings[0];

    for (int i = 0; i < n; i++) {
        total += ratings[i];
        if (ratings[i] > h_rating) {
            h_rating = ratings[i];
            h_index = i;
        }
    }
    float average = (float) total / n;

    printf("---Rating Report---\n");
    printf("Total Ratings in all Categories: %d\n", total);
    printf("Average Ratings per Category: %.2f\n", average);
    printf("Highest Rating Category is %d = %d\n",
           h_index + 1, h_rating);

    int c_index,temp,n_rating;
    printf("Enter the Category NO for Update: ");
    scanf("%d", &temp);
    c_index = temp-1;

    if (temp < 1 || temp > n){
        printf("Invalid category No\n");
    } else {
        printf("Enter new rating count: ");
        scanf("%d", &n_rating);
        ratings[c_index] = n_rating;
        total = 0;
        h_rating = ratings[0];
        h_index = 0;

        for (int i = 0; i < n; i++) {
            total += ratings[i];
            if (ratings[i] > h_rating) {
                h_rating = ratings[i];
                h_index = i;
            }
        }
        average = (float)total / n;
        printf("Updated Rating Analysis\n");
        printf("Total Ratings in all categories: %d\n", total);
        printf("Average Ratings per category: %.2f\n", average);
        printf("Highest Rating Category is now %d = %d\n",
                h_index + 1, h_rating);
    }
    free(ratings);
}
