#include <stdio.h>
#include <math.h>
int main(){
    float a,b,c, discriminant, ans1, ans2,real,imaginary;
    printf("Enter Coefficient of a = ");
    scanf("%f", &a);
    printf("Enter Coefficient of b = ");
    scanf("%f",&b);
    printf("Enter Coefficient of c = ");
 	scanf("%f",&c);
    discriminant = (b*b) - (4*a*c);
    if(discriminant > 0){
        ans1 = (-b + sqrt(discriminant)) / (2*a);
        ans2 = (-b - sqrt(discriminant)) / (2*a);
        printf("Roots are real and distinct\n");
        printf("1st Root = %.2f, 2nd Root = %.2f\n", ans1, ans2);
    }
    else if (discriminant == 0){
            ans1 = -b / (2 * a);
            printf("Roots are real and equal\n");
            printf("Both Roots are Equal and = %.2f\n", ans1);
        }
    else{
        real = -b/(2 * a);
        imaginary = sqrt(-discriminant) / (2 * a);
        printf("Roots are imaginary\n");
        printf("1st Root = %.2f + %.2fi \n", real, imaginary);
        printf("2nd Root = %.2f - %.2fi \n", real, imaginary);
        }
    return 0;
}

