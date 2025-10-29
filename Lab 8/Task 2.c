#include <stdio.h>
int main() {
    char names[5][20];
	int i;
    for (i = 0; i < 5; i++){
    	printf("Enter names of %d student:",i+1);
        scanf("%s", names[i]);
    }
    printf("\n---List of students---\n");
    for (i=0;i<5;i++) {
        printf("%s\n", names[i]);
    }
}


