#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NAME_LENGTH 50

struct Student {
    int id;
    char name[NAME_LENGTH];
    char course[NAME_LENGTH];
    float grade;
};

int main(void)
{
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\nStudent Record System\n");
        printf("1. Add student\n");
        printf("2. Show all students\n");
        printf("3. Search by ID\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            if (count >= MAX_STUDENTS) {
                printf("Record limit reached.\n");
                continue;
            }
            printf("Enter student ID: ");
            scanf("%d", &students[count].id);
            getchar();
            printf("Enter student name: ");
            fgets(students[count].name, NAME_LENGTH, stdin);
            students[count].name[strcspn(students[count].name, "\n")] = '\0';
            printf("Enter course: ");
            fgets(students[count].course, NAME_LENGTH, stdin);
            students[count].course[strcspn(students[count].course, "\n")] = '\0';
            printf("Enter grade: ");
            scanf("%f", &students[count].grade);
            getchar();
            count++;
        } else if (choice == 2) {
            if (count == 0) {
                printf("No student records available.\n");
                continue;
            }
            printf("\nAll Students:\n");
            for (int i = 0; i < count; i++) {
                printf("ID: %d\n", students[i].id);
                printf("Name: %s\n", students[i].name);
                printf("Course: %s\n", students[i].course);
                printf("Grade: %.2f\n\n", students[i].grade);
            }
        } else if (choice == 3) {
            int searchId;
            int found = 0;
            printf("Enter student ID to search: ");
            scanf("%d", &searchId);
            for (int i = 0; i < count; i++) {
                if (students[i].id == searchId) {
                    printf("\nStudent found:\n");
                    printf("ID: %d\n", students[i].id);
                    printf("Name: %s\n", students[i].name);
                    printf("Course: %s\n", students[i].course);
                    printf("Grade: %.2f\n", students[i].grade);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Student with ID %d not found.\n", searchId);
            }
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
