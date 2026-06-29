#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char str[100];
    char str2[100];
    int choice;
    int i, len;
    int count;
    
    while(1)
    {
        printf("\n===== STRING OPERATIONS MENU =====\n");
        printf("1. Input String\n");
        printf("2. Display String\n");
        printf("3. Find Length\n");
        printf("4. Reverse String\n");
        printf("5. Count Vowels\n");
        printf("6. Count Consonants\n");
        printf("7. Convert to Uppercase\n");
        printf("8. Convert to Lowercase\n");
        printf("9. Concatenate Two Strings\n");
        printf("10. Compare Two Strings\n");
        printf("11. Copy String\n");
        printf("12. Exit\n");
        printf("=====================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch(choice)
        {
            case 1:
                printf("Enter a string: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = 0;
                printf("String stored successfully!\n");
                break;
                
            case 2:
                printf("Your string is: %s\n", str);
                break;
                
            case 3:
                len = strlen(str);
                printf("Length of string: %d\n", len);
                break;
                
            case 4:
                printf("Reversed string: ");
                for(i = strlen(str) - 1; i >= 0; i--)
                    printf("%c", str[i]);
                printf("\n");
                break;
                
            case 5:
                count = 0;
                for(i = 0; i < strlen(str); i++)
                {
                    if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
                        count++;
                    if(str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
                        count++;
                }
                printf("Total vowels: %d\n", count);
                break;
                
            case 6:
                count = 0;
                for(i = 0; i < strlen(str); i++)
                {
                    if(isalpha(str[i]))
                    {
                        if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u')
                        {
                            if(str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U')
                                count++;
                        }
                    }
                }
                printf("Total consonants: %d\n", count);
                break;
                
            case 7:
                printf("Uppercase: ");
                for(i = 0; i < strlen(str); i++)
                    printf("%c", toupper(str[i]));
                printf("\n");
                break;
                
            case 8:
                printf("Lowercase: ");
                for(i = 0; i < strlen(str); i++)
                    printf("%c", tolower(str[i]));
                printf("\n");
                break;
                
            case 9:
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0;
                strcat(str, str2);
                printf("Concatenated string: %s\n", str);
                break;
                
            case 10:
                printf("Enter second string to compare: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0;
                if(strcmp(str, str2) == 0)
                    printf("Strings are equal\n");
                else
                    printf("Strings are not equal\n");
                break;
                
            case 11:
                strcpy(str2, str);
                printf("String copied: %s\n", str2);
                break;
                
            case 12:
                printf("Thank you for using this program!\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}