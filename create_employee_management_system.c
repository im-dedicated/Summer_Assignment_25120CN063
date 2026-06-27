#include <stdio.h>
#include <string.h>

#define MAX_EMP 100

typedef struct {
    int id;
    char name[50];
    char department[30];
    float salary;
} Employee;

Employee employees[MAX_EMP];
int employeeCount = 0;

void addEmployee() {
    if (employeeCount >= MAX_EMP) {
        printf("Employee list is full.\n");
        return;
    }

    printf("Enter employee id: ");
    scanf("%d", &employees[employeeCount].id);
    getchar();
    printf("Enter employee name: ");
    fgets(employees[employeeCount].name, sizeof(employees[employeeCount].name), stdin);
    employees[employeeCount].name[strcspn(employees[employeeCount].name, "\n")] = '\0';
    printf("Enter department: ");
    fgets(employees[employeeCount].department, sizeof(employees[employeeCount].department), stdin);
    employees[employeeCount].department[strcspn(employees[employeeCount].department, "\n")] = '\0';
    printf("Enter salary: ");
    scanf("%f", &employees[employeeCount].salary);

    employeeCount++;
    printf("Employee added successfully.\n");
}

void listEmployees() {
    if (employeeCount == 0) {
        printf("No employees to show.\n");
        return;
    }

    printf("\nEmployee Records:\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Department: %s\n", employees[i].department);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("----------------------\n");
    }
}

int findEmployeeById(int id) {
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id)
            return i;
    }
    return -1;
}

void searchEmployee() {
    int id;
    printf("Enter employee id to search: ");
    scanf("%d", &id);

    int index = findEmployeeById(id);
    if (index == -1) {
        printf("Employee not found.\n");
        return;
    }

    printf("ID: %d\n", employees[index].id);
    printf("Name: %s\n", employees[index].name);
    printf("Department: %s\n", employees[index].department);
    printf("Salary: %.2f\n", employees[index].salary);
}

void updateEmployee() {
    int id;
    printf("Enter employee id to update: ");
    scanf("%d", &id);

    int index = findEmployeeById(id);
    if (index == -1) {
        printf("Employee not found.\n");
        return;
    }

    printf("Enter new salary: ");
    scanf("%f", &employees[index].salary);
    printf("Salary updated.\n");
}

void deleteEmployee() {
    int id;
    printf("Enter employee id to delete: ");
    scanf("%d", &id);

    int index = findEmployeeById(id);
    if (index == -1) {
        printf("Employee not found.\n");
        return;
    }

    for (int i = index; i < employeeCount - 1; i++) {
        employees[i] = employees[i + 1];
    }
    employeeCount--;
    printf("Employee removed.\n");
}

int main() {
    int choice;

    do {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. List Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Salary\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                listEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                updateEmployee();
                break;
            case 5:
                deleteEmployee();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
