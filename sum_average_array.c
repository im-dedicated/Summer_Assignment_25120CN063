#include <stdio.h>

int main() {
    int n, i;
    float sum = 0, average;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    for(i = 0; i < n; i++) {
        sum = sum + arr[i];
    }
    
    average = sum / n;
    
    printf("\nSum = %.0f\n", sum);
    printf("Average = %.2f\n", average);
    
    return 0;
}
