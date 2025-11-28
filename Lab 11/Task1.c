#include <stdio.h>
#include <string.h>
#define max_orders 5
#define limit_q 7
#define limt_p 5000.0

struct gift
{
    char name[30];
    char type[30];
    float price;
    int quantity;
};

void inputdetails(struct gift g[], int *n)
{
    printf("Enter the number of gifts [Max %d]: ", max_orders);
    scanf("%d", n);

    if (*n <= max_orders)
    {
        for (int i = 0; i < *n; i++)
        {
            printf("\nEnter details for gift %d\n", i + 1);
            printf("Enter Name: ");
            scanf("%s", g[i].name);
            printf("Enter Type: ");
            scanf("%s", g[i].type);
            printf("Enter Price: ");
            scanf("%f", &g[i].price);
            printf("Enter Quantity: ");
            scanf("%d", &g[i].quantity);
        }
    }
    else
    {
        printf("Number entered is greater than %d\n", max_orders);
        *n = 0;
    }
}

void output_expensive_gift(struct gift g[], int n)
{
    int found = 0;

    for (int i = 0; i < n; i++)
    {
        if (g[i].price > limt_p)
        {
            printf("\nExpensive Gift\n");
            printf("Name: %s\n", g[i].name);
            printf("Type: %s\n", g[i].type);
            printf("Price: %.2f\n", g[i].price);
            printf("Quantity: %d\n", g[i].quantity);
            found = 1;
        }
    }
    if (!found)
    {
        printf("\nNo expensive gifts found.\n");
    }
}

void output_excess_quantity_gifts(struct gift g[], int n)
{
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (g[i].quantity > limit_q)
        {
            printf("\nGift With Large Quantity\n");
            printf("Name: %s\n", g[i].name);
            printf("Type: %s\n", g[i].type);
            printf("Price: %.2f\n", g[i].price);
            printf("Quantity: %d\n", g[i].quantity);
            found = 1;
        }
    }
    if (!found)
    {
        printf("\nNo gifts with excess quantity found.\n");
    }
}

int main()
{
    int x;
    int n = 0;
    int flag = 1;
    struct gift g[max_orders];

    while (flag)
    {
        printf("\nMENU FOR THE GIFT MANAGEMENT\n");
        printf("1: Input new gifts\n");
        printf("2: Output gifts that are expensive\n");
        printf("3: Output gifts available in large quantities\n");
        printf("4: Exit\n");
        printf("Enter choice: ");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            inputdetails(g, &n);
            break;
        case 2:
            output_expensive_gift(g, n);
            break;
        case 3:
            output_excess_quantity_gifts(g, n);
            break;
        case 4:
            flag = 0;
            break;
        default:
            printf("Invalid Option\n");
        }
    }
}
