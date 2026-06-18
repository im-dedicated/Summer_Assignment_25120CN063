#include <stdio.h>

int main()
{
    int arr1[10], arr2[10];
    int n1, n2, i, j;
    
    printf("Enter size of first array: ");
    scanf("%d", &n1);
    
    printf("Enter elements of first array: ");
    for(i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    
    printf("\nEnter size of second array: ");
    scanf("%d", &n2);
    
    printf("Enter elements of second array: ");
    for(i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }
    
    printf("\nCommon elements are: ");
    
    for(i = 0; i < n1; i++)
    {
        for(j = 0; j < n2; j++)
        {
            if(arr1[i] == arr2[j])
            {
                printf("%d ", arr1[i]);
                break;
            }
        }
    }
    
    printf("\n");
    
    return 0;
}
