#include <stdio.h>
#include <string.h>
#define Max_lim 50

int add(int *counter, char arr[][200]){
    char note[200];
    if (*counter >= Max_lim){
        printf("Note limit reached!\n");
        return 0;
    }
    printf("Enter new note (-1 to cancel): ");
    fgets(note, 190, stdin);
    note[strcspn(note, "\n")] = '\0';

    if(strcmp(note, "-1") == 0)
        return 0;
	int i;
    for( i = 0; i < *counter; i++)
        if(strcmp(arr[i], note) == 0){
            printf("Note already exists!\n");
            return 0;
        }

    strcpy(arr[*counter], note);
    printf("Note added successfully!\n");
    return 1;
}

int deleted(char arr[][200], int *counter){
    int i, num;
    printf("Enter note number to delete: ");
    scanf("%d", &num);
    while(getchar() != '\n');

    if(num < 1 || num > *counter){
        printf("Invalid number!\n");
        return 0;
    }

    for( i = num - 1; i < *counter - 1; i++)
        strcpy(arr[i], arr[i + 1]);

    (*counter)--;
    printf("Note deleted successfully!\n");
    return 1;
}

int update(char arr[][200], int *counter){
    int i,num;
    char note[200];

    printf("Enter note number to update: ");
    scanf("%d", &num);
    while(getchar() != '\n');

    if(num < 1 || num > *counter){
        printf("Invalid number!\n");
        return 0;
    }

    printf("Enter new note: ");
    fgets(note, 190, stdin);
    note[strcspn(note, "\n")] = '\0';

    for(i = 0; i < *counter; i++)
        if(strcmp(arr[i], note) == 0 && i != (num - 1)){
            printf("Note already exists!\n");
            return 0;
        }

    strcpy(arr[num - 1], note);
    printf("Note updated successfully!\n");
    return 1;
}

void search(char arr[][200], int *counter){
    int i ;
	char key[200];
    printf("Enter phrase to search: ");
    fgets(key, 190, stdin);
    key[strcspn(key, "\n")] = '\0';

    int found = 0;
    for(i = 0; i < *counter; i++)
        if(strstr(arr[i], key) != NULL){
            printf("%d. %s\n", i + 1, arr[i]);
            found = 1;
        }

    if(!found)
        printf("No matching notes found!\n");
}

void wordcounter(char arr[][200], int *counter){
    char word[50];
    printf("Enter word to count across all notes: ");
    fgets(word, 50, stdin);
    word[strcspn(word, "\n")] = '\0';

    int i , total = 0;
    for( i = 0; i < *counter; i++){
        char *ptr = arr[i];
        while(*ptr != '\0'){
            if(strncmp(ptr, word, strlen(word)) == 0 && (*(ptr + strlen(word)) == ' ' || *(ptr + strlen(word)) == '\0')){
                total++;
                ptr += strlen(word);
            } else {
                ptr++;
            }
        }
    }
    printf("The word \"%s\" appears %d times!\n", word, total);
}

void saving(char arr[][200], int *counter){
    FILE *ptr = fopen("episodes.txt", "w");
    int i;
    for(i = 0; i < *counter; i++)
        fprintf(ptr, "%s\n", arr[i]);
    fclose(ptr);
    printf("All notes saved!\n");
}

int main(){
    FILE *ptr = fopen("episodes.txt", "r+");
    if(ptr == NULL)
        ptr = fopen("episodes.txt", "w+");

    char arr[Max_lim][200];
    int counter = 0;

    while(counter < Max_lim && fgets(arr[counter], 190, ptr) != NULL){
        arr[counter][strcspn(arr[counter], "\n")] = '\0';
        counter++;
    }
    fclose(ptr);

    int choice;
    while(1){
        printf("\n--- PODCAST NOTES MENU ---\n");
        printf("1. Add Note\n2. Delete Note\n3. Update Note\n4. Search Note\n5. Count Word\n6. Save & Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n');

        switch(choice){
            case 1:
                if(add(&counter, arr))
                    counter++;
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
                wordcounter(arr, &counter);
                break;
            case 6:
                saving(arr, &counter);
                return 0;
            default:
                printf("Invalid Option!\n");
        }
    }
}

