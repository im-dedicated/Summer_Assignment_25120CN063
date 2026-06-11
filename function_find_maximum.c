#include<stdio.h>

int findMax(int a, int b, int c)
{
    int max;
    
    if(a > b)
        max = a;
    else
        max = b;
    
    if(c > max)
        max = c;
    
    return max;
}

int main()
{
    int x, y, z, result;
    
    printf("Enter three numbers: ");
    scanf("%d %d %d", &x, &y, &z);
    
    result = findMax(x, y, z);
    
    printf("Maximum number is: %d\n", result);
    
    return 0;
}