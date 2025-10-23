#include <stdio.h>
int main() {
    char arr1[300];
    char highest[30];
    char words[30];
    int i = 0;
    int k = 0;
    printf("Enter the string: ");
    char a = getchar();
    while (a != '\n' && i < 299) {
        arr1[i] = a;
        a = getchar();
        i++;
    }
    arr1[i] = '\0'; 
    i = 0;
    while (arr1[i] != '\0') {
        int j = 0;
        while (arr1[i] != ' ' && arr1[i] != '\0') {
            highest[j] = arr1[i];
            j++;
            i++;
        }
        highest[j] = '\0';
        if (j > k) {
            k = j;
            int x = 0;
            while (x < k) {
                words[x] = highest[x];
                x++;
            }
            words[x] = '\0';
        }
        if (arr1[i] == ' ')
            i++;
    }
    printf("Largest length of word is: %d\n", k);
    printf("Largest length word is: %s\n", words);
}
