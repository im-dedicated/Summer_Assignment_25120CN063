#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1001];
    int i, j;
    int found = 0;

    printf("Enter a string: ");
    if (!fgets(str, sizeof str, stdin))
        return 0;

    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[--len] = '\0';

    for (i = 0; i < (int)len; i++) {
        for (j = i + 1; j < (int)len; j++) {
            if (str[i] == str[j]) {
                printf("First repeating character: %c\n", str[i]);
                found = 1;
                break;
            }
        }
        if (found)
            break;
    }

    if (!found)
        printf("No repeating character found\n");

    return 0;
}
