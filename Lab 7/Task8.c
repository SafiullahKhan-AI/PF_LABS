#include <stdio.h>
int main(){
    char arr1[100];
    char arr2[100];
    int i = 0;
    printf("Enter string 1: ");
    scanf("%s",&arr1);
    printf("Enter string 2: ");
    scanf("%s",&arr2);
    while( arr1[i]!='\0' &&  arr2[i]!='\0'  &&  arr1[i] == arr2[i]) {
        i++;
    }
    if (arr1[i] == '\0' && arr2[i] == '\0')
        printf("Strings are equal.\n");
    else
        printf("Strings are not equal.\n");
    
}
