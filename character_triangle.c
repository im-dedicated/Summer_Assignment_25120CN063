#include <stdio.h>

int main(void)
{
    int rows = 5;
    char letter = 'A';

    for (int i = 1; i <= rows; i++) {
        letter = 'A';
        for (int j = 1; j <= i; j++) {
            putchar(letter);
            if (letter == 'Z') {
                letter = 'A';
            } else {
                letter++;
            }
            if (j < i) {
                putchar(' ');
            }
        }
        putchar('\n');
    }

    return 0;
}
