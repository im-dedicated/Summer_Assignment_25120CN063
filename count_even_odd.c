#include <stdio.h>

int main()
{
    int n, i;
    int even = 0, odd = 0;
    int num;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    
    for(i = 0; i < n; i++)
    {
        scanf("%d", &num);
        
        if(num % 2 == 0)
        {
            even = even + 1;
        }
        else
        {
            odd = odd + 1;
        }
    }
    
    printf("\nEven count: %d\n", even);
    printf("Odd count: %d\n", odd);
    
    return 0;
}
