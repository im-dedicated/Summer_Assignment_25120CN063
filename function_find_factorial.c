#include <stdio.h>

int findFactorial(int num)
{
    int result = 1;
    int i;
    
    for(i = 1; i <= num; i++)
    {
        result = result * i;
    }
    
    return result;
}

int main()
{
    int number;
    int answer;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    if(number < 0)
    {
        printf("Factorial not defined for negative numbers\n");
    }
    else
    {
        answer = findFactorial(number);
        printf("Factorial of %d is %d\n", number, answer);
    }
    
    return 0;
}
