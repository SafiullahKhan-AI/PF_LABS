#include <stdio.h>
int main(){
    int arr[7];
    int i,x;
    for(i=0;i<7;i++){
        printf("Enter the reading %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    x = arr[6];
    for(i=6;i>0;i--){
        arr[i] = arr[i-1];
    }
    arr[0] = x;
    for(i=0;i<7;i++){
        printf("%d ",arr[i]);
    }   
}
