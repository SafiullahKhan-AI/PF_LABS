#include <stdio.h>
#include <string.h>
#define Max_limit 40

int add(int *counter, char arr[][200]) {
    char recipe[200];
    int i;

    if (*counter >= Max_limit) {
        printf("Recipe limit reached!\n");
        return 0;
    }
    printf("Enter recipe name (-1 to cancel): ");
    fgets(recipe, 190, stdin);
    recipe[strcspn(recipe, "\n")] = '\0';
    if(strcmp(recipe, "-1") == 0)
        return 0;

    for(i = 0; i < *counter; i++) {
        if(strcmp(arr[i], recipe) == 0) {
            printf("Recipe already exists!\n");
            return 0;
        }
    }
    strcpy(arr[*counter], recipe);
    printf("Recipe added!\n");
    return 1;
}

void search(char arr[][200], int *counter) {
    char key[200];
    int i, found = 0;
    printf("Enter text to search: ");
    fgets(key, 190, stdin);
    key[strcspn(key, "\n")] = '\0';

    printf("\nSearch Results:\n");

    for(i = 0; i < *counter; i++) {
        if(strstr(arr[i], key) != NULL) {
            printf("%d. %s\n", i+1, arr[i]);
            found = 1;
        }
    }
    if(!found) 
	printf("No recipe found.\n");
}

int update(char arr[][200], int *counter) {
    int num, i;
    char new[200];

    printf("Enter recipe number to update: ");
    scanf("%d", &num);
    while(getchar() != '\n');

    if(num < 1 || num > *counter) {
        printf("Invalid number!\n");
        return 0;
    }

    printf("Enter new recipe name: ");
    fgets(new, 190, stdin);
    new[strcspn(new, "\n")] = '\0';
    for(i = 0; i < *counter; i++){
        if(strcmp(arr[i], new) == 0) {
            printf("Recipe already exists!\n");
            return 0;
        }
    }
    strcpy(arr[num - 1], new);
    printf("Recipe updated!\n");
    return 1;
}

int delete(char arr[][200], int *counter) {
    int num, i;
    printf("Enter recipe number to delete: ");
    scanf("%d", &num);
    while(getchar() != '\n');
    if(num < 1 || num > *counter) {
        printf("Invalid number!\n");
        return 0;
    }

    for(i = num - 1; i < *counter - 1; i++)
        strcpy(arr[i], arr[i+1]);
    (*counter)--;
    printf("Recipe deleted.\n");
    return 1;
}

void sortRecipes(char arr[][200], int *counter) {
    char temp[200];
    int i, j;
    for(i = 0; i < *counter - 1; i++) {
        for(j = i + 1; j < *counter; j++) {
            if(strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

void save(char arr[][200], int *counter) {
    int i;
    sortRecipes(arr, counter);
    FILE *ptr = fopen("recipes.txt", "w");
    for(i = 0; i < *counter; i++)
        fprintf(ptr, "%s\n", arr[i]);

    fclose(ptr);
    printf("Recipes saved to file.\n");
}

int main() {
    FILE *ptr = fopen("recipes.txt", "r");
    if (ptr == NULL)
        ptr = fopen("recipes.txt", "w+");
    char recipes[Max_limit][200];
    int counter = 0;
    while(counter < Max_limit && fgets(recipes[counter], 190, ptr)){
        recipes[counter][strcspn(recipes[counter], "\n")] = '\0';
        counter++;
    }
    fclose(ptr);

    int choice;
    while(1) {
        printf("\n--- RECIPE MENU ---\n");
        printf("1. Add Recipe\n");
        printf("2. Search Recipe\n");
        printf("3. Update Recipe\n");
        printf("4. Delete Recipe\n");
        printf("5. Save Recipes\n");
        printf("Enter -1 to Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);
        while(getchar() != '\n');

        if(choice == -1) {
            save(recipes, &counter);
            printf("Exiting Program!!!\n");
            break;
        }

        switch(choice){
            case 1:
                if(add(&counter, recipes))
                    counter++;
                break;
                
            case 2:
                search(recipes, &counter);
                break;

            case 3:
                update(recipes, &counter);
                break;

            case 4:
                delete(recipes, &counter);
                break;

            case 5:
                save(recipes, &counter);
                break;

            default:
                printf("Invalid choice...Try again\n");
        }
    }
    return 0;
}

