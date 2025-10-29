#include <stdio.h>
int main(){
    int arr[5][4];
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<4;j++){
            printf("Enter marks for student %d of subject %d:",i+1,j+1);
			scanf("%d",&arr[i][j]);
        }
    }
    float avgarr[5];
    float avg;
    int sum;
    for(i=0;i<5;i++){
        sum = 0;
        for(j=0;j<4;j++){
            sum = sum + arr[i][j];
        }
        avg = sum/4;
        avgarr[i] = avg;
    }
    int highest = 0,highestarr[4];
    for(j=0;j<4;j++){
        highest = 0;
        for(i=0;i<5;i++){
            if (arr[i][j] > highest){
                highest = arr[i][j];
            }
        }
        highestarr[j] = highest;
    }
    printf("Average marks for each student: ");
    for(i=0;i<5;i++){
        printf(" %.2f",avgarr[i]);
    }
    printf("\n Highest marks in each subject: ");
    for(i=0;i<4;i++){
        printf(" %d",highestarr[i]);
    }

}
