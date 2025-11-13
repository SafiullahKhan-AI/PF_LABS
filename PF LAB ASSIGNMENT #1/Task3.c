#include <stdio.h>
int main(){
    int len ,arr[len], result[len] , i,j;
    printf("Enter the size of the array: ");
    scanf("%d",&len);
    
    for(i=0;i<len;i++){
        printf("Enter %d Element: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Entered Array: [ ");
    for(i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("]\n");
    
    for(i=0;i<len;i++){
        if(arr[i]%2==0){
            result[i] = 0;
        }
        else{
            result[i] = 1;
        }
    }
    for(i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (result[j] > result[j + 1]) {
            	
                int temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }
    printf("Result Array: [ ");
    for(i=0;i<len;i++){
        printf("%d ",result[i]);
    }
    printf("]\n");
}
