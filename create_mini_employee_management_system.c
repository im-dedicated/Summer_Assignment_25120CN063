#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    char department[30];
    float salary;
};

struct Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Cannot add more employees. Storage full.\n");
        return;
    }

    printf("Enter employee ID: ");
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
    getchar();

    employeeCount++;
    printf("Employee added successfully.\n\n");
}

void listEmployees() {
    if (employeeCount == 0) {
        printf("No employees to show.\n\n");
        return;
    }

    printf("List of employees:\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Department: %s\n", employees[i].department);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("-------------------------\n");
    }
}

int findEmployeeById(int id) {
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            return i;
        }
    }
    return -1;
}

void searchEmployee() {
    if (employeeCount == 0) {
        printf("No employees stored yet.\n\n");
        return;
    }

    int id;
    printf("Enter employee ID to search: ");
    scanf("%d", &id);
    getchar();

    int index = findEmployeeById(id);
    if (index < 0) {
        printf("Employee not found.\n\n");
        return;
    }

    printf("Employee found:\n");
    printf("ID: %d\n", employees[index].id);
    printf("Name: %s\n", employees[index].name);
    printf("Department: %s\n", employees[index].department);
    printf("Salary: %.2f\n\n", employees[index].salary);
}

void removeEmployee() {
    if (employeeCount == 0) {
        printf("No employees to remove.\n\n");
        return;
    }

    int id;
    printf("Enter employee ID to remove: ");
    scanf("%d", &id);
    getchar();

    int index = findEmployeeById(id);
    if (index < 0) {
        printf("Employee not found.\n\n");
        return;
    }

    for (int i = index; i < employeeCount - 1; i++) {
        employees[i] = employees[i + 1];
    }
    employeeCount--;
    printf("Employee removed successfully.\n\n");
}

void updateEmployee() {
    if (employeeCount == 0) {
        printf("No employees to update.\n\n");
        return;
    }

    int id;
    printf("Enter employee ID to update: ");
    scanf("%d", &id);
    getchar();

    int index = findEmployeeById(id);
    if (index < 0) {
        printf("Employee not found.\n\n");
        return;
    }

    printf("Enter new name: ");
    fgets(employees[index].name, sizeof(employees[index].name), stdin);
    employees[index].name[strcspn(employees[index].name, "\n")] = '\0';

    printf("Enter new department: ");
    fgets(employees[index].department, sizeof(employees[index].department), stdin);
    employees[index].department[strcspn(employees[index].department, "\n")] = '\0';

    printf("Enter new salary: ");
    scanf("%f", &employees[index].salary);
    getchar();

    printf("Employee updated successfully.\n\n");
}

int main() {
    int choice;

    do {
        printf("--- Employee Management System ---\n");
        printf("1. Add employee\n");
        printf("2. List employees\n");
        printf("3. Search employee by ID\n");
        printf("4. Update employee\n");
        printf("5. Remove employee\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();

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
                removeEmployee();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n\n");
        }
    } while (choice != 6);

    return 0;
}
