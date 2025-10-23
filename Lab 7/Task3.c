#include <stdio.h>
int main() {
    int arr[100], n, i, value, j, new = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
    	printf("Enter %d element: ",i+155);
        scanf("%d", &arr[i]);
    }
    printf("Enter value to delete: ");
    scanf("%d", &value); 
    for (i = 0; i < n; i++) {
        if (arr[i] != value) {
            arr[new] = arr[i];
            new++;
        }
    }
    printf("Array after deleting %d:\n", value);
    for (i = 0; i < new; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
