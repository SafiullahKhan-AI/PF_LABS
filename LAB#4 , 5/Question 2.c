#include <stdio.h>
int main(){
    int units;
    int total_bill;
    printf("Enter the total number of units consumed: ");
    scanf("%d", &units);
    if(units <= 100){
        total_bill = units * 5;
    } 
	else {
        if (units <= 200) {
            total_bill = (100*5) + (units - 100)*7;
        } 
		else {
            if (units <= 300){
                total_bill = (100*5) + (100*7) + (units-200)*10;
            } 
			else {
                total_bill = (100*5) + (100*7) + (100*10) + (units-300)*15;
            }
        }
    }
    printf("Your Total Bill on Units %d is Rs %d", units, total_bill);
    return 0;
}
