#include<stdio.h>
int main(){
	int num;
	char abc;
	printf("Enter any integer between 65 to 90\n");
	scanf("%d", &num);
	if(num<65 || num>90){
		printf("invalid input integer");
		return 0;
	}
	else{
		abc = (char)num;
		printf("Input-->%d\n",num);
		printf("Output-->%d = %c\n",num,abc);
	}
	return 0;
}
