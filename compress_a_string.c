#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[100];
    int len, count, i;

    printf("Enter a string: ");
    if (fgets(s, sizeof(s), stdin) == NULL)
        return 0;

    len = strlen(s);
    if (len > 0 && s[len - 1] == '\n')
        s[--len] = '\0';

    if (len == 0) {
        printf("Compressed string: \n");
        return 0;
    }

    printf("Compressed string: ");
    count = 1;
    for (i = 1; i <= len; i++) {
        if (i < len && s[i] == s[i - 1]) {
            count++;
        } else {
            printf("%c", s[i - 1]);
            if (count > 1)
                printf("%d", count);
            count = 1;
        }
    }

    printf("\n");
    return 0;
}
