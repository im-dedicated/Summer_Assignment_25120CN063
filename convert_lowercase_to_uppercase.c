#include <stdio.h>

int main(void)
{
    char s[100];
    int i;

    printf("Enter a string: ");
    if (fgets(s, sizeof s, stdin)) {
        for (i = 0; s[i] != '\0'; i++) {
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] = s[i] - 'a' + 'A';
        }

        printf("Uppercase: %s", s);
    }

    return 0;
}
