#include <stdio.h>
int main(){
    int shape, solve;
    float radius,area,perimeter,length,width,base,height,s1,s2,s3;
    printf("----- Geometry Calculator -----\n");
    printf("-----------Shapes---------------\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("Select Shape = ");
    scanf("%d", &shape);
    switch(shape){
        case 1:
        printf("You selected Circle\n");
        printf("1. Area\n");
        printf("2. Perimeter\n");
        printf("Select What You want to calculate = ");
        scanf("%d", &solve);
        
		switch (solve){
            case 1:
            printf("Enter Radius: ");
            scanf("%f", &radius);
            area = 3.142*radius*radius;
            printf("Area of Circle = %.2f\n", area);
            
            break;
            
            case 2:
            printf("Enter Radius: ");
            scanf("%f", &radius);
            perimeter = 2*3.142*radius;
            printf("Perimeter of Circle = %.2f\n", perimeter);
            
			break;
            default:
                printf("Invalid Selection, Please select from above options\n");
        }
        break;

       	 	case 2:
        	printf("You selected Rectangle\n");
       		printf("1. Area\n");
       		printf("2. Perimeter\n");
       		printf("Select What You want to calculate = ");
        	scanf("%d", &solve);
        	    switch (solve) {
                case 1:
                printf("Enter Length: ");
                scanf("%f", &length);
                printf("Enter Width: ");
            	scanf("%f",&width);
                area = length*width;
                printf("Area of Rectangle = %.2f\n",area);
                
                break;
                
                case 2:
                printf("Enter Length: ");
                scanf("%f", &length);
                printf("Enter Width: ");
            	scanf("%f",&width);
                perimeter = 2*(length + width);
                printf("Perimeter of Rectangle = %.2f\n", perimeter);
                
                break;
                default:
                    printf("Invalid Selection, Please select from above options\n");
            }
        break;
        
        	case 3:
    		printf("You selected Triangle\n");
        	printf("1. Area\n");
        	printf("2. Perimeter\n");
        	printf("Select What You want to calculate = ");
            scanf("%d", &solve);
            switch (solve){
                case 1:
                printf("Enter Base: ");
                scanf("%f", &base);
                printf("Enter Height: ");
            	scanf("%f",&height);
                    area = 0.5*base*height;
                    printf("Area of Triangle = %.2f\n", area);
                    
                break;
                case 2: 
                printf("Enter Length of 1st Side: ");
                scanf("%f", &s1);
                printf("Enter Length of 2nd Side: ");
            	scanf("%f",&s2);
            	printf("Enter Length of 3rd Side: ");
                scanf("%f", &s3);
                perimeter = s1+s2+s3;
                printf("Perimeter of Triangle = %.2f\n", perimeter);
                    
                break;
                default:
                    printf("Invalid Selection, Please select from above options\n");
            }
        break;
        default:
            printf("Invalid Selection, Please select from above options\n");
    }
    return 0;
}

