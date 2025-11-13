#include <stdio.h>
int main(){
    int len , arr[len],result[len];
    
    printf("Enter the size of an array (only even number allow!): ");
    scanf("%d",&len);
    while(len%2!=0){
        printf("Enter the correct size of an arry ( Even number only!): ");
        scanf("%d",&len);
    }
    
    int x = len/2;
    int y = x;
    int i;
    int j = 0;
    
    for(i=0;i<len;i++){
        printf("Enter %d Element: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Entered Array: [ ");
    for(i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("]\n");

    for(i=0;i<x;i++){
        result[j] = arr[i];
        j++;
        result[j] = arr[y];
        j++;
        y++;
    }
    printf("Result Array: [ ");
    for( i=0;i<len;i++){
        printf("%d ",result[i]);
    }
    printf("]\n");

}
