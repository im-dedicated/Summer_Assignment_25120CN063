#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[1000];
    char longest[1000];
    int i, len, curr_len = 0, max_len = 0;
    int start = 0, max_start = 0;

    printf("Enter a sentence:\n");
    if (!fgets(s, sizeof(s), stdin))
        return 0;

    len = strlen(s);
    if (len > 0 && s[len - 1] == '\n')
        s[--len] = '\0';

    for (i = 0; i <= len; i++) {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\0') {
            curr_len++;
        } else {
            if (curr_len > max_len) {
                max_len = curr_len;
                max_start = start;
            }
            curr_len = 0;
            start = i + 1;
        }
    }

    if (max_len == 0) {
        printf("No word found\n");
        return 0;
    }

    strncpy(longest, s + max_start, max_len);
    longest[max_len] = '\0';

    printf("Longest word: %s\n", longest);
    return 0;
}
