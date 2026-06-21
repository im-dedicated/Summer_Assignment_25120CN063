#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    printf("Reversed string: ");
    for (i = len - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    putchar('\n');

    return 0;
}
