#include <stdio.h>
int main() {
    int dpt,course;
    printf("------University Course Registration------\n");
    printf("Select Department: \n");
    printf("1. Computer Science (CS)\n");
    printf("2. Electrical Engineering (EE)\n");
    printf("3. Business Administration (BBA)\n");
    printf("Select Course Number = ");
    scanf("%d", &dpt);
    switch (dpt){
    case 1:
    printf("-----Computer Science-----");
    printf("CS Courses:\n");
    printf("1. Programming Fundamentals\n");
    printf("2. Web Development\n");
    printf("3. Database Systems\n");
    printf("Select Course Number = ");
    scanf("%d", &course);

        switch (course) {
        case 1:
        printf("You Registered for Programming Fundamentals\n");
        break;
        
        case 2:
        printf("You Registered for Web Development\n");
        break;
        
        case 3:
            printf("You Registered for Database Systems\n");
        break;
        
        default:
            printf("Invalid Course Selection\n");
        }
        break;

    case 2:
        printf("-----Electrical Engineering-----\n");
        printf("EE Courses:\n");
        printf("1. Digital Logic Design\n");
        printf("2. Power Systems\n");
        printf("3. Electronics\n");
        printf("Select Course Number = ");
        scanf("%d", &course);

        switch (course){
        case 1:
            printf("You Registered for Digital Logic Design\n");
        break;
        
        case 2:
        printf("You Registered for Power Systems\n");
        break;
        
        case 3:
        printf("You Registered for Electronics\n");
        break;
        
        default:
            printf("Invalid Course Selection\n");
        }  
    break;

    case 3:
        printf("-----Business Administration-----\n");
        printf("BBA Courses:\n");
        printf("1. Business Mathematics\n");
        printf("2. Principle of Marketing\n");
        printf("3. Principle of Management\n");
    	printf("Select Course Number = ");
        scanf("%d", &course);

        switch (course) {
        case 1:
        printf("You Registered for Business Mathematics\n");
        break;
        
        case 2:
        printf("You Registered for Principle of Marketing\n");
        break;
        
        case 3:
        printf("You Registered for Principle of Management\n");
        break;
        default:
            printf("Invalid Course Selection\n");
        }
    break;

    default:
        printf("Invalid Department Selection\n");
    }
    return 0;
}
