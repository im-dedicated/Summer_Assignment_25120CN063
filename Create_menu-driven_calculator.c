#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int choice;
	double a, b, result;

	while (1) {
		printf("\nSimple Calculator\n");
		printf("1. Addition\n");
		printf("2. Subtraction\n");
		printf("3. Multiplication\n");
		printf("4. Division\n");
		printf("5. Modulus (integers)\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		if (scanf("%d", &choice) != 1) {
            
			int c; while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Invalid input. Please enter a number between 1 and 6.\n");
			continue;
		}

		if (choice == 6) {
			printf("Exiting.\n");
			break;
		}

		if (choice < 1 || choice > 6) {
			printf("Please choose a valid option (1-6).\n");
			continue;
		}

		if (choice == 5) {

			long ia, ib;
			printf("Enter two integers separated by space: ");
			if (scanf("%ld %ld", &ia, &ib) != 2) {
				int c; while ((c = getchar()) != '\n' && c != EOF) {}
				printf("Invalid input.\n");
				continue;
			}
			if (ib == 0) {
				printf("Cannot divide by zero.\n");
				continue;
			}
			printf("Result: %ld\n", ia % ib);
			continue;
		}

		printf("Enter two numbers separated by space: ");
		if (scanf("%lf %lf", &a, &b) != 2) {
			int c; while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Invalid input.\n");
			continue;
		}

		switch (choice) {
			case 1:
				result = a + b;
				printf("Result: %.6g\n", result);
				break;
			case 2:
				result = a - b;
				printf("Result: %.6g\n", result);
				break;
			case 3:
				result = a * b;
				printf("Result: %.6g\n", result);
				break;
			case 4:
				if (b == 0) {
					printf("Cannot divide by zero.\n");
				} else {
					result = a / b;
					printf("Result: %.6g\n", result);
				}
				break;
			default:
				printf("Unknown option.\n");
		}
	}

	return 0;
}

