#include <stdio.h>

int main(void)
{
    int age;

    printf("Enter your age: ");
    if (scanf("%d", &age) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (age >= 18) {
        printf("You are eligible to vote.\n");
    } else {
        printf("You are not eligible to vote yet.\n");
    }

    return 0;
}
