#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[200];
    int i, j;

    printf("Enter a string: ");
    if (fgets(s, sizeof s, stdin) == NULL)
        return 0;

    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n')
        s[len - 1] = '\0';

    j = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ')
            s[j++] = s[i];
    }
    s[j] = '\0';

    printf("Result: %s\n", s);
    return 0;
}
