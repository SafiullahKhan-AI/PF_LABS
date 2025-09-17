#include<stdio.h>
int main(){
	int a , b ,c;
	printf("Enter value of a :\n");
	scanf("%d", &a);
	printf("Enter value of b :\n");
	scanf("%d", &b);
	printf("Input--> a = %d , b = %d\n", a ,b);
	c = a;
	a = b;
	b = c;
	printf("Output--> a = %d , b = %d", a ,b);
	return 0;
}
