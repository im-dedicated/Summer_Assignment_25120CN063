#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 20
#define SUBJECTS 5

struct Student {
    char name[50];
    int roll;
    int marks[SUBJECTS];
};

void clearInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Student list is full.\n");
        return;
    }

    printf("Enter roll number: ");
    scanf("%d", &students[*count].roll);
    clearInput();

    printf("Enter name: ");
    fgets(students[*count].name, sizeof(students[*count].name), stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0';

    for (int i = 0; i < SUBJECTS; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%d", &students[*count].marks[i]);
    }
    clearInput();

    (*count)++;
    printf("Student added successfully.\n");
}

float calculateAverage(const struct Student *student) {
    int sum = 0;
    for (int i = 0; i < SUBJECTS; i++) {
        sum += student->marks[i];
    }
    return (float)sum / SUBJECTS;
}

void displayStudent(const struct Student *student) {
    printf("Roll: %d\n", student->roll);
    printf("Name: %s\n", student->name);
    for (int i = 0; i < SUBJECTS; i++) {
        printf("Subject %d marks: %d\n", i + 1, student->marks[i]);
    }
    printf("Average: %.2f\n", calculateAverage(student));
    printf("-------------------------\n");
}

void displayStudents(const struct Student students[], int count) {
    if (count == 0) {
        printf("No students in the list.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        displayStudent(&students[i]);
    }
}

int findStudentByRoll(const struct Student students[], int count, int roll) {
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            return i;
        }
    }
    return -1;
}

void searchStudent(const struct Student students[], int count) {
    if (count == 0) {
        printf("No students available to search.\n");
        return;
    }

    int roll;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);
    clearInput();

    int index = findStudentByRoll(students, count, roll);
    if (index < 0) {
        printf("Student not found.\n");
    } else {
        displayStudent(&students[index]);
    }
}

void topStudent(const struct Student students[], int count) {
    if (count == 0) {
        printf("No students to evaluate.\n");
        return;
    }

    int best = 0;
    float bestAvg = calculateAverage(&students[0]);
    for (int i = 1; i < count; i++) {
        float avg = calculateAverage(&students[i]);
        if (avg > bestAvg) {
            bestAvg = avg;
            best = i;
        }
    }
    printf("Top student details:\n");
    displayStudent(&students[best]);
}

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\nCollege Student Record System\n");
        printf("1. Add student\n");
        printf("2. Display all students\n");
        printf("3. Search student by roll number\n");
        printf("4. Show top student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInput();

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                topStudent(students, count);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
