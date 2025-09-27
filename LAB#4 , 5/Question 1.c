#include <stdio.h>
int main(){
    int num1, num2, num3, x;
    printf("Enter 1st number: ");
    scanf("%d", &num1);
    printf("Enter 2nd number: ");
    scanf("%d", &num2);
    printf("Enter 3rd number: ");
    scanf("%d" ,&num3);
    if (num1 > num2) {
        if (num1 > num3){
            if (num2 > num3){
            x = num2;
			}
            else{
            x = num3;
        	} 
    	}
		else{
        x = num1;
        }
    } 
	else{
        if (num2 > num3){
            if (num1 > num3){
                x = num1;}
            else{
                x = num3;}
   		 }	
		else{
            x = num2;
        }
	}		
	printf("The second largest number is: %d\n", x);
    return 0;
}

