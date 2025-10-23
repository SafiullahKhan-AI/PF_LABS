#include <stdio.h>
int main(){
    int arr1[7],arr2[7],totalarr[14];
    int i;
    printf("------1st Sensor Reading------\n");
    for(i=0;i<7;i++){
        printf("Enter reading number %d: ",i+1);
        scanf("%d",&arr1[i]);
    }
        printf("------2nd Sensor Reading------\n");
    for(i=0;i<7;i++){
        printf("Enter reading number %d: ",i+1);
        scanf("%d",&arr2[i]);
    }
    int j = 0;
    for (i = 0; i < 7; i++){
        totalarr[j] = arr1[i];
        j++;
    }
    for (i = 0; i < 7; i++) {
        totalarr[j] = arr2[i];
        j++;
    }
    printf("------Merged Reading-------\n");
    for (i = 0; i < 14; i++) {
        printf("%d ", totalarr[i]);
    }
}
