#include <stdio.h>

int main()
{
    int arr[5];
    int i;
    
    printf("Enter 5 array elements:\n");
    
    for(i = 0; i < 5; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    printf("\nArray elements are:\n");
    
    for(i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
