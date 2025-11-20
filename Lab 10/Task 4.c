#include <stdio.h>
#include <string.h>
#define Max_Lim 50  

int add(int *counter, char arr[][200]) {
    char text[200];
    if (*counter >= Max_Lim) {
        printf("Affirmation limit reached!!!\n");
        return 0;
    }
    printf("Enter new Affirmation (-1 to cancel): ");
    fgets(text, 190, stdin);
    text[strcspn(text, "\n")] = '\0';
    if(strcmp(text, "-1") == 0) return 0;
    int words = 1;
    char *p;
    for(p = text; *p != '\0'; p++)
    if (*p == ' ') words++;
        
    if(words > 7) {
        printf("Affirmation more than 7 words, not added.\n");
        return 0;
    }
    int i;
    for(i = 0; i < *counter; i++)
        if(strcmp(arr[i], text) == 0) {
            printf("Affirmation already exists!\n");
            return 0;
        }
    strcpy(arr[*counter], text);
    printf("Affirmation added!\n");
    return 1;
}

int deleted(char arr[][200], int *counter) {
    int num, i;
    printf("Enter affirmation number to delete: ");
    scanf("%d", &num);
    while (getchar() != '\n');
    if(num < 1 || num > *counter) {
        printf("Invalid number!\n");
        return 0;
    }
    for(i = num - 1; i < *counter - 1; i++)
        strcpy(arr[i], arr[i + 1]);

    (*counter)--;
    printf("Affirmation Deleted!\n");
    return 1;
}

int update(char arr[][200], int *counter) {
    int num, i;
    char text[200];
    printf("Enter Affirmation number to Update: ");
    scanf("%d", &num);
    while (getchar() != '\n');
    if(num < 1 || num > *counter) {
        printf("Invalid Number!\n");
        return 0;
    }
    printf("Enter new Affirmation: ");
    fgets(text, 190, stdin);
    text[strcspn(text, "\n")] = '\0';

    int words = 1;
    char *p; 
    for(p = text; *p != '\0'; p++)
        if (*p == ' ') words++;
    if(words > 7) {
        printf("More than 7 words, not updated.\n");
        return 0;
    }
    for(i = 0; i < *counter; i++)
        if(strcmp(arr[i], text) == 0) {
            printf("Affirmation already exists.\n");
            return 0;
        }
    strcpy(arr[num - 1], text);
    printf("Affirmation Updated!\n");
    return 1;
}

void search(char arr[][200], int *counter) {
    char key[200];
    printf("Enter Phrase to Search: ");
    fgets(key, 190, stdin);
    key[strcspn(key, "\n")] = '\0';

    int found = 0;
    int i;
    for(i = 0; i < *counter; i++)
        if(strstr(arr[i], key) != NULL) {
            printf("%d. %s\n", i + 1, arr[i]);
            found = 1;
        }
    if(!found) 
        printf("No Match Present\n");
}

void save(char arr[][200], int *counter) {
    FILE *ptr = fopen("affirmation.txt", "w");
    if(ptr == NULL) {
        printf("Error saving file!\n");
        return;
    }
    int i;
    for (i = 0; i < *counter; i++)
        fprintf(ptr, "%s\n", arr[i]);
    fclose(ptr);
    printf("All Affirmations saved!\n");
}

int main() {
    char arr[Max_Lim][200];
    int counter = 0;

    FILE *ptr = fopen("affirmation.txt", "r");
    if(ptr) {
        while(counter < Max_Lim && fgets(arr[counter], 190, ptr)) {
            arr[counter][strcspn(arr[counter], "\n")] = '\0';
            counter++;
        }
        fclose(ptr);
    }

    int choice;
    while(1) {
        printf("\n--- AFFIRMATION MENU ---\n");
        printf("1. Add Affirmation\n");
        printf("2. Delete Affirmation\n");
        printf("3. Update Affirmation\n");
        printf("4. Search Affirmation\n");
        printf("5. Save & Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n');

        switch(choice) {
            case 1:
                if(add(&counter, arr)) counter++;
                break;
            case 2:
                deleted(arr, &counter);
                break;
            case 3:
                update(arr, &counter);
                break;
            case 4:
                search(arr, &counter);
                break;
            case 5:
                save(arr, &counter);
                return 0;
            default:
                printf("Invalid Option!\n");
        }
    }
}

