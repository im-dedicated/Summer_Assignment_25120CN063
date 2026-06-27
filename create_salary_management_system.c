#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 50

struct Employee {
    int id;
    char name[40];
    float salary;
};

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int count = 0;
    int option;
    int i;
    int searchId;
    float totalPayroll;

    do {
        printf("\nSalary Management System\n");
        printf("1. Add employee\n");
        printf("2. Update salary\n");
        printf("3. Show all employees\n");
        printf("4. Show total payroll\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (count >= MAX_EMPLOYEES) {
                    printf("Employee list is full.\n");
                } else {
                    printf("Enter ID: ");
                    scanf("%d", &employees[count].id);
                    printf("Enter name: ");
                    getchar();
                    fgets(employees[count].name, sizeof(employees[count].name), stdin);
                    employees[count].name[strcspn(employees[count].name, "\n")] = '\0';
                    printf("Enter salary: ");
                    scanf("%f", &employees[count].salary);
                    count++;
                }
                break;
            case 2:
                if (count == 0) {
                    printf("No employees available.\n");
                } else {
                    printf("Enter employee ID to update: ");
                    scanf("%d", &searchId);
                    for (i = 0; i < count; i++) {
                        if (employees[i].id == searchId) {
                            printf("Current salary of %s is %.2f\n", employees[i].name, employees[i].salary);
                            printf("Enter new salary: ");
                            scanf("%f", &employees[i].salary);
                            break;
                        }
                    }
                    if (i == count) {
                        printf("Employee ID not found.\n");
                    }
                }
                break;
            case 3:
                if (count == 0) {
                    printf("No employee records to show.\n");
                } else {
                    printf("\nID\tName\t\tSalary\n");
                    for (i = 0; i < count; i++) {
                        printf("%d\t%s\t\t%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
                    }
                }
                break;
            case 4:
                totalPayroll = 0.0f;
                for (i = 0; i < count; i++) {
                    totalPayroll += employees[i].salary;
                }
                printf("Total payroll for %d employee(s) is %.2f\n", count, totalPayroll);
                break;
            case 5:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid option, try again.\n");
        }
    } while (option != 5);

    return 0;
}
