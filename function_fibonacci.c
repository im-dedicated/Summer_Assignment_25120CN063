#include <stdio.h>

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    
    int a = 0, b = 1, c;
    int i;
    
    for (i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    
    return b;
}

int main()
{
    int num, result;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (num < 0)
    {
        printf("Please enter a positive number\n");
    }
    else
    {
        result = fibonacci(num);
        printf("Fibonacci number at position %d is %d\n", num, result);
    }
    
    return 0;
}
