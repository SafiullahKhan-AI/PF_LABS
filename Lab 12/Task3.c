#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int containsDigit(char *str) {
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            return 1;  
        }
        str++;
    }
    return 0;  
}

int main() {
    int n;
    char store[200];
    printf("Enter no of usernames: ");
    scanf("%d", &n);
    getchar(); 
    char **usernames = malloc(n * sizeof(char *));

    if (usernames == NULL){
        printf("Memory Allocation fail\n");
        return 1;
    }
    printf("Enter %d usernames:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Username %d: ", i + 1);
        fgets(store, sizeof(store), stdin);
        store[strcspn(store, "\n")] = '\0';

        usernames[i] = (char *)malloc(strlen(store) + 1);
        if (usernames[i] == NULL) {
            printf("Memory allocation fail\n");
            return 1;
        }

        strcpy(usernames[i], store);
    }
    printf("\n---Valid Usernames(MO DIGITS)---\n");
    for (int i = 0; i < n; i++) {
        if (!containsDigit(usernames[i])) {
            printf("%s\n", usernames[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        free(usernames[i]);  
    }
    free(usernames);
    printf("\nProgram ending.\n");
    return 0;
}
