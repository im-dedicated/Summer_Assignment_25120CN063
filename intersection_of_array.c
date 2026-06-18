#include <stdio.h>

int main()
{
    int arr1[10], arr2[10];
    int n1, n2;
    int i, j, k;
    int intersection[10];
    int count = 0;

    printf("Enter size of first array: ");
    scanf("%d", &n1);
    
    printf("Enter elements of first array: ");
    for(i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n2);
    
    printf("Enter elements of second array: ");
    for(i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    for(i = 0; i < n1; i++)
    {
        for(j = 0; j < n2; j++)
        {
            if(arr1[i] == arr2[j])
            {
                int found = 0;
                for(k = 0; k < count; k++)
                {
                    if(intersection[k] == arr1[i])
                    {
                        found = 1;
                        break;
                    }
                }
                if(found == 0)
                {
                    intersection[count] = arr1[i];
                    count++;
                }
                break;
            }
        }
    }

    if(count == 0)
    {
        printf("No common elements found.\n");
    }
    else
    {
        printf("Intersection of arrays: ");
        for(i = 0; i < count; i++)
        {
            printf("%d ", intersection[i]);
        }
        printf("\n");
    }

    return 0;
}
