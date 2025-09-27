#include <stdio.h>
int main(){
    int age, movie;
    char ticket[30];
    printf("Enter your Age: ");
    scanf("%d", &age);
    if (age < 12){
        printf("You Will Have Child Ticket.\n");
     	sprintf(ticket, "Child Ticket");
    }
    else if (age <= 60) {
        printf("You Will Have Adult Ticket.\n");
        sprintf(ticket, "Adult Ticket");
    	}
    	else{
        printf("You Will Have Senior Citizen Ticket.\n");
        sprintf(ticket, "Senior Citizen Ticket");
    	}
    	
    printf("---Movies Cateogory--\n");
    printf("1. Action\n");
    printf("2. Comedy\n");
    printf("3. Horror\n");
    printf("Select Category: ");
    scanf("%d", &movie);
    switch (movie) {
        case 1:
            printf("You booked %s for Action Movie.\n", ticket);
            break;
        case 2:
            printf("You booked %s for Comedy Movie.\n", ticket);
            break;
        case 3:
            printf("You booked %s for Horror Movie.\n", ticket);
            break;
        default:
            printf("Invalid Movie Category\n");
    }
    return 0;
}

