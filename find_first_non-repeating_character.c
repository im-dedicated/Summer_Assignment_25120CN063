#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int count[256] = {0};
    int i, len;
    
    printf("Enter a string: ");
    if(fgets(str, sizeof(str), stdin) == NULL) return 0;
    /* remove trailing newline */
    len = strlen(str);
    if(len > 0 && str[len-1] == '\n') str[--len] = '\0';
    

    
    for(i = 0; i < len; i++)
    {
        unsigned char c = (unsigned char)str[i];
        if(c == ' ') continue; /* ignore spaces */
        count[c]++;
    }


    for(i = 0; i < len; i++)
    {
        unsigned char c = (unsigned char)str[i];
        if(c == ' ') continue;
        if(count[c] == 1)
        {
            printf("First non-repeating character is: %c\n", c);
            return 0;
        }
    }
    
    printf("No non-repeating character found\n");
    
    return 0;
}
