#include <stdio.h>
#include <string.h>

int main()
{
    char text[1001];
    int freq[256] = {0};
    int i, length, maxCount = 0;
    unsigned char maxChar = 0;

    printf("Enter a string:\n");
    if (fgets(text, sizeof text, stdin) == NULL)
        return 0;

    length = strlen(text);
    if (length > 0 && text[length - 1] == '\n')
        text[--length] = '\0';

    for (i = 0; i < length; i++) {
        if (text[i] == ' ')
            continue;
        freq[(unsigned char)text[i]]++;
    }

    for (i = 0; i < 256; i++) {
        if (freq[i] > maxCount) {
            maxCount = freq[i];
            maxChar = (unsigned char)i;
        }
    }

    if (maxCount > 0) {
        if (maxChar == ' ')
            printf("Maximum occurring character: [space] (occurred %d times)\n", maxCount);
        else if (maxChar == '\t')
            printf("Maximum occurring character: [tab] (occurred %d times)\n", maxCount);
        else if (maxChar == '\n')
            printf("Maximum occurring character: [newline] (occurred %d times)\n", maxCount);
        else if (maxChar < 32 || maxChar == 127)
            printf("Maximum occurring character: [ASCII %d] (occurred %d times)\n", maxChar, maxCount);
        else
            printf("Maximum occurring character: %c (occurred %d times)\n", maxChar, maxCount);
    } else
        printf("No characters found.\n");

    return 0;
}
