#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[1000];
    int seen[256] = {0};
    int i, j = 0;

    if (fgets(s, sizeof s, stdin) == NULL)
        return 0;

    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n')
        s[--len] = '\0';

    for (i = 0; i < len; i++) {
        unsigned char c = (unsigned char)s[i];
        if (!seen[c]) {
            seen[c] = 1;
            s[j++] = s[i];
        }
    }
    s[j] = '\0';

    printf("%s\n", s);
    return 0;
}
