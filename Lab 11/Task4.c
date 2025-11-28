#include <stdio.h>
#include <string.h>

char* palindrome(char myarr[], int letter_count, int i){
    static char string[200];    

    if(letter_count < 0){
        string[i] = '\0';
        return string;
    }

    string[i] = myarr[letter_count];
    return palindrome(myarr, letter_count - 1, i + 1);
}

int main(){
    char myarr[50];
    int flag = 1, x;

    while(flag){
        printf("1:Enter a word\n");
        printf("2:Exit the program\n");
        scanf("%d",&x);

        switch(x){
            case 1:
                printf("Input a word: ");
                scanf("%s", myarr);
                if(strcmp(myarr, palindrome(myarr, strlen(myarr) - 1, 0)) == 0)
                    printf("Palindrome\n");
                else
                    printf("Not Palindrome\n");
                break;

            case 2:
                flag = 0;
                printf("Exiting program...\n");
                break;
        }
    }
}
