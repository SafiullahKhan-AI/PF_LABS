#include <stdio.h>

void event_countdown(int a)
{
    if (a == 0)
    {
        printf("%d\n", a);
    }
    else
    {
        printf("%d\n", a);
        event_countdown(a - 1);
    }
}

int main()
{
    int flag = 1;
    int x;
    int a;
    char event_name[100];
    while (flag)
    {
        printf("1:Input Event\n");
        printf("2:Exit program\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("Enter the event Name: ");
            scanf("%s", event_name);
            printf("Enter the number of days: ");
            scanf("%d", &a);
            event_countdown(a);
            break;
        case 2:
            flag = 0;
            printf("Program exited successfully...\n");
            break;
        default:
            printf("Enter the correct number only\n");
            break;
        }
    }
}