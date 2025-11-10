#include <stdio.h>
int data(int arr[],int n){
    int count, i,j,k;
    for(i=0;i<n;i++){
        printf("Enter Total number of Vehicles of Road %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter the Target Vehicle Count: ");
    scanf("%d",&count);
    
    int flag = 0;
    
    for(j=0 ;j<n;j++){
        for(k=j+1;k<n;k++){
            if (arr[j] + arr[k] == count){
                printf("Target is found at Road number %d and %d\n", j+1, k+1);
                flag = 1;
            }
        }
    }
    if (!flag){
    printf("No Pair of Roads is Found with this Target\n");
	}
}
int main(){
    int n;
    printf("Enter the total number of Roads: ");
    scanf("%d",&n);
    int arr[n];
    data(arr,n);

}





