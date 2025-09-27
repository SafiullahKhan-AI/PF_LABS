#include <stdio.h>

int main() {
    int category, option;
    printf("------ Library Management System ------\n");
    printf("-------------Categories----------------\n");
    printf("1. Books\n");
    printf("2. Magazines\n");
    printf("Select Category: ");
    scanf("%d", &category);

    switch(category){
        case 1:
            printf("---Books--\n");
            printf("What You Want?\n");
            printf("1. Issue Book\n");
            printf("2. Return Book\n");
            printf("Select Desired Option: ");
            scanf("%d", &option);

            switch(option){
                case 1:
                printf("Book is Issued\n");
                break;
                
                case 2:
                printf("Book is Returned\n");
                break;
                
                default:
                printf("Invalid Option Selected\n");
            }
        break;

        case 2:
        printf("---Magazines---\n");
        printf("What You Want?\n");
        printf("1. Issue Magazine\n");
        printf("2. Return Magazine\n");
        printf("Choose Desired Option: ");
        scanf("%d", &option);

            switch (option) {
                case 1:
                printf("Magazine is Issued\n");
                break;
                
                case 2:
                printf("Magazine is Returned\n");
                break;
                
                default:
                printf("Invalid Option Selected\n");
            }
        break;

        default:
            printf("Invalid Category Selected\n");
    }
    return 0;
}

