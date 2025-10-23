#include <stdio.h>
int main(){
    int arr[10],i;
    for(i =0; i<10;i++){
        printf("Enter reading number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("BEFORE REVERSING: ");
    for(i =0;i<10;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    int *p1 = arr;
    int *p2 = arr + 9;
    int x;
    while(p1<p2){
        x = *p1;
        *p1 = *p2;
        *p2 = x;
        p1 ++;
        p2 --;
    }
    printf("AFTER REVERSIMG: ");
    for(i =0;i<10;i++){
        printf("%d ",arr[i]);
    }

}
