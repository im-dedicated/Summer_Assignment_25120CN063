#include <stdio.h>

int checkPrime(int num)
{
    int i;
    
    if (num <= 1)
        return 0;
    
    if (num == 2)
        return 1;
    
    if (num % 2 == 0)
        return 0;
    
    for (i = 3; i * i <= num; i = i + 2)
    {
        if (num % i == 0)
            return 0;
    }
    
    return 1;
}

int main()
{
    int n;
    
    printf("Enter a number: ");
    scanf("%d", &n);
    
    if (checkPrime(n))
        printf("%d is prime\n", n);
    else
        printf("%d is not prime\n", n);
    
    return 0;
}
