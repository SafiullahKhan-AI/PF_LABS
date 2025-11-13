#include <stdio.h>
int main(){
    int len, arr[len], i, j;
    printf("Enter the length of array: ");
    scanf("%d",&len);
    
    for( i=0;i<len;i++){
        printf("Enter %d Element: ",i+1);
        scanf("%d", &arr[i]);
    }
    printf("Entered Array: [ ");
    for(i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("]\n");
    int result[len];
    int sum;
    for( i=0;i<len;i++){
        sum = 0;
        for( j=0;j<=i;j++){
            sum = sum + arr[j];
        }
        result[i] = sum;
    }
    printf("Result Array: [ ");
    for(i=0;i<len;i++){
        printf("%d ", result[i]);
    }
    printf("]\n");
}
