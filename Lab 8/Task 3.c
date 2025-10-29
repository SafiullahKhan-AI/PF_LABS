#include <stdio.h>

int main() {
    char arr[3][10];
    int i, j;
    int counter = 0;
    printf("Enter character:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 10; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }
    for (i = 0; i < 3; i++){
        for (j = 0; j < 10; j++){
            char ch = arr[i][j];
            if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || 
			ch == 'i' || ch == 'I' || ch == 'o' || 
			ch == 'O' || ch == 'u' || ch == 'U'){
                counter++;
            }
        }
    }
    printf("\nTotal vowels = %d\n", counter);
    return 0;
}
