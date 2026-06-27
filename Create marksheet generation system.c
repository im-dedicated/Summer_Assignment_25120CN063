#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[50], roll[20], branch[30], college[50];
    int n, i;
    float marks[10], total = 0, percentage;
    char grade;

    printf("===== MARKSHEET GENERATION SYSTEM =====\n");

    printf("Enter student name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter roll number: ");
    fgets(roll, sizeof(roll), stdin);
    roll[strcspn(roll, "\n")] = '\0';

    printf("Enter branch: ");
    fgets(branch, sizeof(branch), stdin);
    branch[strcspn(branch, "\n")] = '\0';

    printf("Enter college name: ");
    fgets(college, sizeof(college), stdin);
    college[strcspn(college, "\n")] = '\0';

    printf("Enter number of subjects: ");
    scanf("%d", &n);

    printf("\nEnter marks of %d subjects:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Subject %d: ", i + 1);
        scanf("%f", &marks[i]);

        if (marks[i] < 0 || marks[i] > 100)
        {
            printf("Invalid marks. Enter between 0 and 100.\n");
            i--;
        }
        else
        {
            total += marks[i];
        }
    }

    percentage = total / n;

    if (percentage >= 90)
        grade = 'A';
    else if (percentage >= 80)
        grade = 'B';
    else if (percentage >= 70)
        grade = 'C';
    else if (percentage >= 60)
        grade = 'D';
    else if (percentage >= 40)
        grade = 'E';
    else
        grade = 'F';

    printf("\n========== MARKSHEET ==========" );
    printf("\nStudent Name : %s", name);
    printf("\nRoll Number  : %s", roll);
    printf("\nBranch       : %s", branch);
    printf("\nCollege      : %s", college);
    printf("\nSubjects     : %d", n);
    printf("\nTotal Marks  : %.2f", total);
    printf("\nPercentage   : %.2f%%", percentage);
    printf("\nGrade        : %c", grade);
    printf("\n===============================\n");

    return 0;
}
