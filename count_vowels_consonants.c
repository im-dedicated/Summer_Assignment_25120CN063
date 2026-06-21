#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int vowels = 0, consonants = 0;

    printf("Enter a line of text:\n");

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (isalpha((unsigned char)ch)) {
            ch = tolower((unsigned char)ch);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    return 0;
}
