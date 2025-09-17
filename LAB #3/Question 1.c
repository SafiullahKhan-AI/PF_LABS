#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	float num1 , num2 , num3 , total , percent;
	printf("Enter the Marks of 1st Subject out of 100:\n");
	scanf("%f", &num1);
	printf("Enter the Marks of 2nd Subject out of 100:\n");
	scanf("%f", &num2);
	printf("Enter the Marks of 3rd Subject out of 100:\n");
	scanf("%f", &num3);
	total = num1+num2+num3;
	percent = (total*100)/300;
	printf("-----------------------------\n");
	printf("The Total Marks are %.2f and Percentage is %.2f %%" , total , percent);
	return 0;
}
