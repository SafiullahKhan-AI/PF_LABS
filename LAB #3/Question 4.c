#include<stdio.h>
int main(){
	float Basic_Sal, HRA , DA , Gross_Sal;
	printf("Enter Basic Salary:\n");
	scanf("%f", &Basic_Sal);
	HRA = 0.1*Basic_Sal;
	DA = 0.05*Basic_Sal;
	Gross_Sal= Basic_Sal+HRA+DA;
	printf("----------------------------------------\n");
	printf("On Basic Salary %f , House Rent Allowance (HRA) is %f, Dearness Allowance is %f\n", Basic_Sal,HRA,DA);
	printf("----------------------------------------\n");
	printf("Gross Salary is %.2f", Gross_Sal);
	return 0;
}
