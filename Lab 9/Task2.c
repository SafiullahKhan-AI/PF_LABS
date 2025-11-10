#include <stdio.h>
float Calc_Bonus(int a){
    float bonus;
    if(a<30000){
        bonus = (a*0.2);
    }
    else{
        bonus = (a*0.1);
    }
    return bonus;
}
int main(){
    int num;
    float sum = 0.00;
    printf("Enter the Number of Employees: ");
    scanf("%d",&num);
    
    int i , arr[num];
    for(i=0;i<num;i++){
        printf("Enter the salary for employee %d: ",i+1);
        scanf("%d", &arr[i]);
        float x = Calc_Bonus(arr[i]);
        sum = sum + x + arr[i];
        printf("Employee %d Bonus: %.2f\n",i+1,x);
    }
    printf("-----------------------------\n");
    printf("Total Payout: %.2f",sum);
}

