#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    char **feedback;
    char store[500];  
    int total_char = 0;  

    printf("Enter number of feedback entries: ");
    scanf("%d", &n);

    getchar();  
    feedback = (char **)malloc(n * sizeof(char *));
    if (feedback == NULL) {
        printf("Memory allocation Fail...\n");
        return 1;
    }

    printf("Enter each feedback message:\n");
    for (int i = 0; i < n; i++) {
        printf("Feedback %d: ", i + 1);
        fgets(store, sizeof(store), stdin);
        store[strcspn(store, "\n")] = '\0';

        feedback[i] = (char *)malloc((strlen(store) + 1) * sizeof(char));

        if (feedback[i] == NULL) {
            printf("Memory allocation fail\n");
            return 1;
        }
        strcpy(feedback[i], store);
    }
    
    for (int i = 0; i < n; i++) {
        total_char += strlen(feedback[i]);
    }
    char *longest = feedback[0];
    for (int i = 1; i < n; i++) {
        if (strlen(feedback[i]) > strlen(longest)) {
            longest = feedback[i];
        }
    }
    printf("All Feedback Entries\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %s\n", i + 1, feedback[i]);
    }
    printf("\nTotal Characters in All Entries: %d\n", total_char);
    printf("Longest Feedback:\n%s\n", longest);
    for (int i = 0; i < n; i++) {
        free(feedback[i]);  
    }
    free(feedback);
    printf("Program complete.\n");
}
