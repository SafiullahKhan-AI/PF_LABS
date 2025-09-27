#include <stdio.h>
int main() {
    char username[20];
    int password;
    printf("Enter Username: ");
    scanf("%s", username);
    if (username [0] == 'a'&& username [1] == 'd' && username [2] == 'm'&& username [3] == 'i'&& username [4] == 'n'){
        printf("Enter Password (XXXX): ");
        scanf("%d", &password);
        if(password == 1234){
           printf("Login Successfully\n");
        }
        else{
            printf("Incorrect Password\n");
            printf("Login Unsuccessful");
        }
    }
    else{
        printf("Invalid Username\n");
        printf("Login Unsuccessful");
    }
    return 0;
}

