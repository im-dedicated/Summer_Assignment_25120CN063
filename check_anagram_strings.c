#include <stdio.h>
#include <string.h>

int main(void)
{
    char s1[100], s2[100];
    int count[256] = {0};
    int i;

    printf("Enter first string: ");
    if (!fgets(s1, sizeof(s1), stdin))
        return 1;
    printf("Enter second string: ");
    if (!fgets(s2, sizeof(s2), stdin))
        return 1;

    if (s1[strlen(s1) - 1] == '\n')
        s1[strlen(s1) - 1] = '\0';
    if (s2[strlen(s2) - 1] == '\n')
        s2[strlen(s2) - 1] = '\0';

    if (strlen(s1) != strlen(s2)) {
        printf("Not anagrams\n");
        return 0;
    }

    for (i = 0; s1[i] != '\0'; i++)
        count[(unsigned char)s1[i]]++;
    for (i = 0; s2[i] != '\0'; i++)
        count[(unsigned char)s2[i]]--;

    for (i = 0; i < 256; i++) {
        if (count[i] != 0) {
            printf("Not anagrams\n");
            return 0;
        }
    }

    printf("Strings are anagrams\n");
    return 0;
}
