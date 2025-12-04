#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int charCategory(char c){
    if (isupper(c)) 
    return 1;
    if (islower(c)) 
    return 2;
    if (isdigit(c)) 
    return 3;
    else
    return 4;  
}

float similarity(char *pattern, char *password){
    int patt_Len = strlen(pattern);
    int pass_Len = strlen(password);
    int compareLen = (patt_Len < pass_Len) ? patt_Len : pass_Len;

    int matchCount = 0;

    for (int i = 0; i < compareLen; i++) {
        if (charCategory(pattern[i]) == charCategory(password[i])){
            matchCount++;
        }
    }

    return ( (float)matchCount / patt_Len ) * 100.0;
}

int main() {
    int n;
    printf("Enter number of participants: ");
    scanf("%d", &n);

    getchar();

    char **passwords = malloc(n * sizeof(char *));
    if (passwords == NULL) {
        printf("Memory allocation fail\n");
        return 1;
    }
    char *pattern = NULL;
    int patternSize = 100;
    pattern = (char *)malloc(patternSize * sizeof(char));

    printf("Enter password pattern: ");
    fgets(pattern, patternSize, stdin);

    pattern[strcspn(pattern, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        int size = 100;
        passwords[i] = (char *)malloc(size * sizeof(char));

        printf("Participant %d password: ", i + 1);
        fgets(passwords[i], size, stdin);
        passwords[i][strcspn(passwords[i], "\n")] = '\0';
    }
    printf("Similarity %%\n");

    float *percent = (float *)malloc(n * sizeof(float));
    float highest = 0;
    int h_index = 0;

    for (int i = 0; i < n; i++) {
        percent[i] = similarity(pattern, passwords[i]);
        printf("Password: %-20s Similarity: %.2f%%\n", passwords[i], percent[i]);

        if (percent[i] > highest) {
            highest = percent[i];
            h_index = i;
        }
    }
    printf("Password with highest Similarity:\n");
    printf(" %s (%.2f%%)\n", passwords[h_index], highest);
    free(pattern);

    for (int i = 0; i < n; i++) {
        free(passwords[i]);
    }
    free(passwords);
    free(percent);

    return 0;
}
