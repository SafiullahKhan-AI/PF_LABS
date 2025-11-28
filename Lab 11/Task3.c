#include <stdio.h>
# define min 18
# define max 15


struct employee{
    char name[50];
    int id;
    int pres_counter;
};


int total_attendance(struct employee e[],int sum,int emp_counter){
    if(emp_counter==0){
        return sum;
    }
    else{
        return total_attendance(e,sum+e[emp_counter-1].pres_counter,emp_counter-1);
    }
}


void input(struct employee e[],int *n){
    printf("Enter the no of employess(Max = 18): ");
    scanf("%d",n);

    if(*n<max){
        for(int i=0; i<*n; i++){
            printf("Enter details for employee %d\n",i+1);
            printf("Name: ");
            scanf("%s",e[i].name);
            printf("ID: ");
            scanf("%d",&e[i].id);
            printf("Attendance: ");
            scanf("%d",&e[i].pres_counter);
        }
    }
    else{
        printf("Number entered is greater than Maximum limit.");
        *n = 0;
    }
}


void output_low_attendance(struct employee e[],int n){
    int x = 1;
    for(int i = 0; i<n; i++){

        if(e[i].pres_counter<min){
            printf("Employee %d with low attendance:\n",x);
            printf("Name: %s\n",e[i].name);
            printf("ID: %d\n",e[i].id);
            printf("Attendance: %d\n",e[i].pres_counter);
            x++;
        }
    }
}

int main(){
    printf("WELCOME TO THE MANAGEMENT SYSTEM OF OUR COMPANY.\n");
    struct employee e[max];
    int x,n=0,flag=1;
    int sum = 0;

    while(flag){
        printf("MAIN MENU:\n");
        printf("1:INPUT DETAILS.\n");
        printf("2:OUTPUT TOTAL ATTENDANCE.\n");
        printf("3:OUTPUT LOW ATTENDANCE EMPLOYEES DETAILS.\n");
        printf("4:EXIT THE PROGRAM.\n");
        printf("ENTER THE NUMBER: ");
        scanf("%d",&x);

        switch(x){
            case 1:
                input(e,&n);
                break;
            case 2:
                printf("Total Attendance = %d\n",total_attendance(e,0,n));
                break;
            case 3:
                output_low_attendance(e,n);
                break;
            case 4:
                printf("Exiting Successfully...");
                flag = 0;
                break;
            default:
                printf("Invalid Option!!!\n");
        }

    }
}


