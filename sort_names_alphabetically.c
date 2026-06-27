#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, i, j;
    char names[50][50];
    char temp[50];

    printf("Enter number of names: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 50) {
        return 0;
    }
    getchar();

    for (i = 0; i < n; i++) {
        printf("Enter name %d: ", i + 1);
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    printf("\nSorted names:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
