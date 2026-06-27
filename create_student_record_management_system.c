#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

struct Student {
    int roll_no;
    char name[50];
    float marks[5];
    float total;
    float avg;
};

int student_count = 0;
struct Student students[MAX_STUDENTS];

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Cannot add more students!\n");
        return;
    }
    
    printf("Enter Roll Number: ");
    scanf("%d", &students[student_count].roll_no);
    printf("Enter Name: ");
    scanf("%s", students[student_count].name);
    
    int i;
    float sum = 0;
    for (i = 0; i < 5; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%f", &students[student_count].marks[i]);
        sum = sum + students[student_count].marks[i];
    }
    
    students[student_count].total = sum;
    students[student_count].avg = sum / 5;
    
    student_count++;
    printf("Student added successfully!\n");
}

void display_students() {
    if (student_count == 0) {
        printf("No students found!\n");
        return;
    }
    
    int i, j;
    printf("\n========== STUDENT RECORDS ==========\n");
    for (i = 0; i < student_count; i++) {
        printf("\nRoll No: %d\n", students[i].roll_no);
        printf("Name: %s\n", students[i].name);
        printf("Marks: ");
        for (j = 0; j < 5; j++) {
            printf("%.1f ", students[i].marks[j]);
        }
        printf("\n");
        printf("Total: %.1f\n", students[i].total);
        printf("Average: %.2f\n", students[i].avg);
    }
    printf("\n=====================================\n");
}

void search_student() {
    int roll;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);
    
    int i;
    for (i = 0; i < student_count; i++) {
        if (students[i].roll_no == roll) {
            printf("\nRoll No: %d\n", students[i].roll_no);
            printf("Name: %s\n", students[i].name);
            printf("Total: %.1f\n", students[i].total);
            printf("Average: %.2f\n", students[i].avg);
            return;
        }
    }
    printf("Student not found!\n");
}

void delete_student() {
    int roll;
    printf("Enter roll number to delete: ");
    scanf("%d", &roll);
    
    int i, j;
    for (i = 0; i < student_count; i++) {
        if (students[i].roll_no == roll) {
            for (j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("Student deleted!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

int main(void) {
    int choice;
    
    while (1) {
        printf("\n===== STUDENT RECORD SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                delete_student();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
