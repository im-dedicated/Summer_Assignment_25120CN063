#include <stdio.h>

int main(void)
{
    char str[100];
    int len = 0;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin)) {
        while (str[len] != '\0' && str[len] != '\n') {
            len++;
        }
        printf("Length = %d\n", len);
    }

    return 0;
}
