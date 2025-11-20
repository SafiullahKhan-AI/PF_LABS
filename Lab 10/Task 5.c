#include <stdio.h>
#include <string.h>
#define Max_Lim 50

int addTag(int *counter, char arr[][200]) {
    char tag[200];
    int words, i;
    char *p;
    if (*counter >= Max_Lim) {
        printf("Tag Limit reached!\n");
        return 0;
    }

    printf("Enter New Tag (-1 to cancel):\n");
    fgets(tag, 190, stdin);
    tag[strcspn(tag, "\n")] = '\0';

    if(strcmp(tag, "-1") == 0) 
	return 0;

    words = 1;
    p = tag;
    while(*p != '\0') {
        if(*p == ' ') words++;
        p++;
    }
    if(words < 5 || words > 7){
        printf("Tag must be 5-7 words!\n");
        return 0;
    }

    for(i = 0; i < *counter; i++){
        if(strcmp(arr[i], tag) == 0){
            printf("Tag already exists!\n");
            return 0;
        }
    }

    strcpy(arr[*counter], tag);
    printf("Tag added!\n");
    return 1;
}

int deleteTag(char arr[][200], int *counter){
    int num, i;
    printf("Enter tag number to delete:\n");
    scanf("%d", &num);
    while(getchar() != '\n');

    if(num < 1 || num > *counter){
        printf("Invalid number!\n");
        return 0;
    }

    for(i = num - 1; i < *counter - 1; i++){
        strcpy(arr[i], arr[i + 1]);
    }
    (*counter)--;
    printf("Tag deleted!\n");
    return 1;
}

int updateTag(char arr[][200], int *counter){
    int num, words, i;
    char tag[200];
    char *p;

    printf("Enter tag number to update:\n");
    scanf("%d", &num);
    while (getchar() != '\n');

    if(num < 1 || num > *counter){
        printf("Invalid number!\n");
        return 0;
    }
    printf("Enter new tag:\n");
    fgets(tag, 190, stdin);
    tag[strcspn(tag, "\n")] = '\0';

    words = 1;
    p = tag;
    while(*p != '\0') 
        if (*p == ' ') words++;
        p++;
    
	if (words < 5 || words > 7){
        printf("Tag must be 5-7 words!\n");
        return 0;
    }

    for(i = 0; i < *counter; i++){
        if (strcmp(arr[i], tag) == 0 && i != (num - 1)){
            printf("Tag already exists!\n");
            return 0;
        }
    }

    strcpy(arr[num - 1], tag);
    printf("Tag Updated!\n");
    return 1;
}

void searchTag(char arr[][200], int *counter){
    char key[200];
    int i, found = 0;

    printf("Enter phrase to search:\n");
    fgets(key, 190, stdin);
    key[strcspn(key, "\n")] = '\0';

    char *start = key;
    while(*start == ' ') start++;

    if (*start == '\0') {
        printf("Empty search!!!\n");
        return;
    }

    printf("Search results:\n");
    for(i = 0; i < *counter; i++){
        if (strstr(arr[i], start) != NULL) {
            printf("%d. %s\n", i + 1, arr[i]);
            found = 1;
        }
    }

    if(!found) 
        printf("No Match found!\n");
    }

void sortTags(char arr[][200], int *counter) {
    char temp[200];
    int i, j;
    for (i = 0; i < *counter - 1; i++) {
        for (j = i + 1; j < *counter; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

void saveTags(char arr[][200], int *counter) {
    int i;
    sortTags(arr, counter);
    FILE *ptr = fopen("tags.txt", "w");
    for (i = 0; i < *counter; i++) {
        fprintf(ptr, "%s\n", arr[i]);
    }
    fclose(ptr);
    printf("All tags saved!\n");
}

int main() {
    char arr[Max_Lim][200];
    int counter = 0;
    int choice;
    int i;
    FILE *ptr = fopen("tags.txt", "r+");
    if (ptr == NULL)
        ptr = fopen("tags.txt", "w+");

    while (counter < Max_Lim && fgets(arr[counter], 190, ptr) != NULL) {
        arr[counter][strcspn(arr[counter], "\n")] = '\0';
        counter++;
    }
    fclose(ptr);
    while (1) {
        printf("\n--- TAG MENU ---\n");
        printf("1. Add Tag\n");
        printf("2. Delete Tag\n");
        printf("3. Update Tag\n");
        printf("4. Search Tag\n");
        printf("5. Save & Exit\n");
        printf("Enter choice:\n");
        scanf("%d", &choice);
        while(getchar() != '\n');

        switch(choice) {
            case 1:
                if (addTag(&counter, arr)) {
                    counter++;
                }
                break;
            case 2:
                deleteTag(arr, &counter);
                break;
            case 3:
                updateTag(arr, &counter);
                break;
            case 4:
                searchTag(arr, &counter);
                break;
            case 5:
                saveTags(arr, &counter);
                return 0;
            default:
                printf("Invalid Option!\n");
        }
    }
    return 0;
}


