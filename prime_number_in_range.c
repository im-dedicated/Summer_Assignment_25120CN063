#include <stdio.h>

int main()
{
    int start, end, i, j, flag;
    
    printf("Enter starting number: ");
    scanf("%d", &start);
    
    printf("Enter ending number: ");
    scanf("%d", &end);
    
    printf("\nPrime numbers between %d and %d are:\n", start, end);
    
    for(i = start; i <= end; i++)
    {
        flag = 1;
        
        for(j = 2; j < i; j++)
        {
            if(i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        
        if(flag == 1 && i > 1)
        {
            printf("%d\n", i);
        }
    }
    
    return 0;
}
