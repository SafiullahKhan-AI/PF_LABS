#include <stdio.h>
void value(int a){
    a = 85;
}

void refer(int *a){
    *a = 85;
}

int main(){
    int a = 80;
    printf("Before UpdateValue: %d\n",a);
    
    value(a);
    printf("After UpdateValue: %d(No change) \n",a);
    printf("Before UpdateReference: %d\n",a);
    
    refer(&a);
    printf("After UpdateReference: %d(Updated successfully)\n",a);
}
