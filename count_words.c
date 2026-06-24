#include <stdio.h>
#include <ctype.h>

int main(void) {
    char line[1000];
    int i = 0, in_word = 0, count = 0;

    if (fgets(line, sizeof line, stdin) == NULL) return 0;

    while (line[i]) {
        if (isspace((unsigned char)line[i])) {
            in_word = 0;
        } else {
            if (!in_word) {
                count++;
                in_word = 1;
            }
        }
        i++;
    }

    printf("%d\n", count);
    return 0;
}
