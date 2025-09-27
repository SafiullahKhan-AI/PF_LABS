#include <stdio.h>
#include <math.h>
int main(){
    int type;
    float loan,rate,time,sinterest, cinterest, totalamount, emi;
    printf("Enter Loan Amount: ");
    scanf("%f", &loan);
    printf("Enter Time (in years): ");
    scanf("%f", &time);
    printf("Enter Annual Interest Rate (in %%): ");
    scanf("%f",&rate);
    printf("Select Interest Type\n");
    printf(" 1.Simple  2.Compound = ");
    scanf("%d", &type);
    if(type == 1) {
        sinterest = (loan*rate*time) / 100;
        totalamount = loan + sinterest;
        emi = totalamount/(time*12);
        printf("Your Interest Type is Simple Interest\n");
        printf("EMI = %.2f\n", emi);
    }
    else {
        if (type == 2) {
            totalamount = loan * pow((1 + rate / 100.0), time);
            emi = totalamount / (time*12);
            printf("Your Interest Type is Compound Interest\n");
            printf("EMI = %.2f\n", emi);
        }
        else {
            printf("\nInvalid Interest Type\n");
        }
    }

    return 0;
}

