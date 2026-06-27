#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char words[100][50];

    printf("How many words do you want to enter? ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        printf("Enter word %d: ", i + 1);
        fgets(words[i], sizeof(words[i]), stdin);

        // Remove the newline character
        words[i][strcspn(words[i], "\n")] = '\0';
    }

    // Sort words by length
    for (int i = 0; i < n - 1; i++) {
        int smallest = i;

        for (int j = i + 1; j < n; j++) {
            if (strlen(words[j]) < strlen(words[smallest])) {
                smallest = j;
            }
        }

        if (smallest != i) {
            char temp[50];
            strcpy(temp, words[i]);
            strcpy(words[i], words[smallest]);
            strcpy(words[smallest], temp);
        }
    }

    printf("\nWords sorted by length:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}