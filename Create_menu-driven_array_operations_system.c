#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main(void)
{
    int arr[MAX];
    int n = 0;
    int choice;
    int i, pos, val, found;

    do {
        printf("\nArray Operations Menu:\n");
        printf("1. Create array\n");
        printf("2. Insert element\n");
        printf("3. Delete element\n");
        printf("4. Search element\n");
        printf("5. Display array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                if (n < 0 || n > MAX) {
                    printf("Invalid size. Use 0 to %d.\n", MAX);
                    n = 0;
                } else {
                    for (i = 0; i < n; i++) {
                        printf("Enter element %d: ", i + 1);
                        scanf("%d", &arr[i]);
                    }
                }
                break;

            case 2:
                if (n >= MAX) {
                    printf("Array is full. Cannot insert more elements.\n");
                } else {
                    printf("Enter position to insert (1 to %d): ", n + 1);
                    scanf("%d", &pos);
                    if (pos < 1 || pos > n + 1) {
                        printf("Invalid position.\n");
                    } else {
                        printf("Enter value to insert: ");
                        scanf("%d", &val);
                        for (i = n; i >= pos; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[pos - 1] = val;
                        n++;
                    }
                }
                break;

            case 3:
                if (n == 0) {
                    printf("Array is empty. Nothing to delete.\n");
                } else {
                    printf("Enter position to delete (1 to %d): ", n);
                    scanf("%d", &pos);
                    if (pos < 1 || pos > n) {
                        printf("Invalid position.\n");
                    } else {
                        for (i = pos - 1; i < n - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        n--;
                    }
                }
                break;

            case 4:
                if (n == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Enter value to search: ");
                    scanf("%d", &val);
                    found = -1;
                    for (i = 0; i < n; i++) {
                        if (arr[i] == val) {
                            found = i;
                            break;
                        }
                    }
                    if (found == -1) {
                        printf("Value %d not found in array.\n", val);
                    } else {
                        printf("Value %d found at position %d.\n", val, found + 1);
                    }
                }
                break;

            case 5:
                if (n == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array elements: ");
                    for (i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
