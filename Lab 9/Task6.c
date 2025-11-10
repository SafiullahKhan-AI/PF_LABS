#include <stdio.h>
#include <string.h>

char *formatName(char *first, char *last){
   	static char fullname[100] = "";
   	
    strcat(fullname, first);
    strcat(fullname, " ");
    strcat(fullname, last);
    return fullname;
}

int main(){  
    char first[50], last[50];
    printf("Enter first name: ");
    scanf("%s", first);
    printf("Enter last name: ");
    scanf("%s", last);
    
    char *fullname = formatName(&first[0], &last[0]);
    printf("Formatted Full Name: %s\n", fullname);
}
