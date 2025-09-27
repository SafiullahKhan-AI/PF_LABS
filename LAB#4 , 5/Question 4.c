#include <stdio.h>
int main(){
	int category, order;
	printf("----------Online Food Order----------\n");
	printf("-----------Food Categories------------\n");
	printf("1. Fast Food\n");
	printf("2. Drinks\n");
	printf("Select Food Category = ");
	scanf("%d", &category);
	switch(category){
	
	case 1:
		printf("--Fast Food--\n");
		printf("1--Burger with French Fries\n");
		printf("2--Pizza\n");
		printf("3--Broast\n");
		printf("4--Wraps\n");
		printf("Select Fast Food You Want to Order = ");
		scanf("%d", &order);
		switch(order){
		case 1:
		printf("You Order Burger with French Fries");
		break;
		case 2:
		printf("You Order Pizza");
		break;
		case 3:
		printf("You Order Broast");
		break;
		case 4:
		printf("You Order Wraps");
		break;
		default:
			printf("Invalid Category Please Choose from above Categories (1-4)");	
		}
	break;
	
	case 2:
		printf("--Drinks--\n");
		printf("1--Tea\n");
		printf("2--Coffee\n");
		printf("3--Cold_Drinks\n");
		printf("4--Juices\n");
		printf("5--Milkshakes\n");
		printf("Select Drink You Want to Order = ");
		scanf("%d", &order);
		switch(order){
		case 1:
		printf("You Order Tea");
		break;
		case 2:
		printf("You Order Coffee");
		break;
		case 3:
		printf("You Order Cold_Drink");
		break;
		case 4:
		printf("You Order Juice");
		break;
		case 5:
		printf("You Order Milkshake");
		break;	
		default:
			printf("Invalid Category Please Choose from above Categories (1-5)");
		}
	break;
	default:
		printf("Invalid Category Please Choose from above Categories (1,2)");
	}
	return 0;			
}
