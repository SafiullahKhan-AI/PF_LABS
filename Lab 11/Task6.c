#include <stdio.h>
#include <string.h>
#define max_item 100
struct Item {
    char name[50];
    char category[50];
    int quantity;
};
void display_all(struct Item *p, int count){

    for (int k = 0; k < count; k++) {
        printf("Name: %s | Category: %s | Quantity: %d\n",
               (p + k)->name,
               (p + k)->category,
               (p + k)->quantity);
    }
}
void filter_Category(struct Item *p, int count, const char *category) {
    int found = 0;

    for (int k = 0; k < count; k++) {
        struct Item *temp = p + k;

        if (strcmp(temp->category, category) == 0) {
            printf("Name: %s | Category: %s | Quantity: %d\n",
                   temp->name,
                   temp->category,
                   temp->quantity);
            found = 1;
        }
    }

    if (!found){
        printf("No items found in this category.\n");
    }
}
void filter_MinQuantity(struct Item *p, int count, int minQty) {
    int found = 0;

    for (int k = 0; k < count; k++) {
        struct Item *temp = p + k;

        if (temp->quantity >= minQty) {
            printf("Name: %s | Category: %s | Quantity: %d\n",
                   temp->name,
                   temp->category,
                   temp->quantity);
            found = 1;
        }
    }

    if (!found) {
        printf("No items found with quantity >= %d.\n", minQty);
    }
}
int main() {
    int n,q;
    char cat[50];
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item i[max_item];


    for (int x = 0; x < n; x++) {
        printf("\nEnter item %d details:\n", x + 1);

        printf("Name: ");
        scanf("%s", i[x].name);

        printf("Category: ");
        scanf("%s", i[x].category);

        printf("Quantity: ");
        scanf("%d", &i[x].quantity);
    }
    struct Item *ptr = i; 

    printf("FULL INVENTORY \n");
    display_all(ptr, n);

    printf("Enter category to filter: ");
    scanf("%s", cat);

    printf("FILTER: CATEGORY = %s\n", cat);
    filter_Category(ptr, n, cat);

    printf("\nEnter minimum quantity: ");
    scanf("%d", &q);
    printf("FILTER: QUANTITY >= %d \n", q);
    filter_MinQuantity(ptr, n, q);

    return 0;
}

