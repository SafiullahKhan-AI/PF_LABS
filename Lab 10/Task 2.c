#include <stdio.h>
#include <string.h>

int addlevel(int *i,char arr[][200]){
    char array[200];

    if(*i < 10){
        printf("Enter the Level: ");
        fgets(array,190,stdin);
        array[strcspn(array,"\n")] = '\0';

        int a,b, counter = 0;
        for(a = 0; array[a] != '\0'; a++){
            if(array[a] == ' ')
                counter++;
        }

        counter++; 
        if(counter > 7){
            printf("Level not Added (More then 7 word) \n");
            return 0;
        }

        for( b = 0; b < *i; b++){
            if(strcmp(arr[b],array) == 0){
                printf("Level is already Stored\n");
                return 0;
            }
        }

        strcpy(arr[*i], array);
        printf("Level Added Successfully!\n");
        return 1;
    }

    return 0;
}

int searchlevel(char arr[][200],int *i){
    int level;
    printf("Enter the level for Fetching the name of: ");
    scanf("%d",&level);
    while (getchar() != '\n');

    if (level >= 1 && level <= *i){
        printf("Level name: %s\n", arr[level - 1]);
        return 1;
    }
    else{
        printf("Level out of range!!!\n");
        return 0;
    }
}

int updatelevel(char arr[][200], int *i){
    int level;
    char newname[200];
    printf("Enter the level number to Update: ");
    scanf("%d", &level);

    while (getchar() != '\n');
    if (level < 1 || level > *i) {
        printf("Level not in range!!!\n");
        return 0;
        }

    printf("Enter the New name: ");
    fgets(newname, 190, stdin);
    newname[strcspn(newname, "\n")] = '\0';

    int a,b, counter = 0;
    for(a = 0; newname[a] != '\0'; a++){
        if(newname[a] == ' ')
            counter++;
    }
    counter++;
    if(counter > 7){
        printf("Level contains more than 7 words! Not updated level.\n");
        return 0;
    }

    for (b = 0; b < *i; b++) {
        if (strcmp(arr[b], newname) == 0) {
            printf("This name already exists!\n");
            return 0;
        }
    }

    strcpy(arr[level - 1], newname);
    printf("Level Updated Successfully\n");
    return 1;
}

int deletelevel(char arr[][200], int *i){
    int level,a;

    printf("Enter the level number to Delete: ");
    scanf("%d",&level);
    while(getchar() != '\n');

    if(level < 1 || level > *i){
        printf("Level out of range!!!\n");
        return 0;
    }

    for( a = level - 1; a < *i - 1; a++){
        strcpy(arr[a], arr[a + 1]);
    }

    (*i)--;
    printf("Level Deleted Successfully\n");
    return 1;
}

void savefile(char arr[][200], int *i){
    FILE *ptr = fopen("levels.txt","w");
    int a;
    for( a = 0; a < *i; a++){
        fprintf(ptr, "%s\n", arr[a]);
    }
    fclose(ptr);
    printf("All changes saved to file.\n");
}

int main(){
    FILE *ptr;
    ptr = fopen("levels.txt","r+");
    if(ptr == NULL){
        ptr = fopen("levels.txt","w+");
    }

    char arr[10][200];
    int i = 0;
    while (i < 10 && fgets(arr[i],190,ptr) != NULL){
        arr[i][strcspn(arr[i],"\n")] = '\0';
        i++;
    }

    int choice;

    while(1){
        printf("\n--- MENU ---\n");
        printf("1. Add Level\n");
        printf("2. Search Level\n");
        printf("3. Update Level\n");
        printf("4. Delete Level\n");
        printf("5. Save & Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n');

        if(choice == 1){
            if(addlevel(&i, arr))
                i++;
        }
        else if(choice == 2){
            searchlevel(arr, &i);
        }
        else if(choice == 3){
            updatelevel(arr, &i);
        }
        else if(choice == 4){
            deletelevel(arr, &i);
        }
        else if(choice == 5){
            savefile(arr, &i);
            break;
        }
        else{
            printf("Invalid choice!\n");
        }
    }

    fclose(ptr);
    return 0;
}

