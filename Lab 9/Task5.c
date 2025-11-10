#include <stdio.h>
void analyzeData( int *arr, int n, int *max, int *min, float *avg ){
    *max = arr[0];
    *min = arr[0];
    int i;
    int sum = 0;
    for(i = 0;i<n;i++){
        sum = sum + arr[i];
        if(arr[i]>*max){
            *max = arr[i];
        }
        else if(arr[i]<*min){
            *min = arr[i];
        }

    }
    *avg = sum/n;
}

int main(){
    int n;
    printf("Enter the Length of Array: ");
    scanf("%d",&n);
    
    int i, arr[n];
    for( i = 0;i<n;i++){
        printf("Enter %d Number: ",i+1);
        scanf("%d",&arr[i]);
    }
    int max = 0;
    int min = 0;
    float avg = 0.0;
    analyzeData(arr,n,&max,&min,&avg);
    printf("Maximum = %d\n",max);
    printf("Minimum = %d\n",min);
    printf("Average = %.2f\n",avg);
}
