#include <stdio.h>

int main() {
	int pin = 1234;
	int enteredPin;
	double balance = 1000.00;
	int choice;
    
	printf("Welcome to the ATM!\n");
	printf("Please enter your PIN: ");
	scanf("%d", &enteredPin);
    
	if (enteredPin != pin) {
		printf("Incorrect PIN. Please try again.\n");
		return 1;
	}
    
	do {
		printf("\nATM Menu:\n");
		printf("1. Check Balance\n");
		printf("2. Withdraw Money\n");
		printf("3. Deposit Money\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
        
		switch (choice) {
			case 1:
				printf("Your balance is: $%.2f\n", balance);
				break;
			case 2: {
				double withdrawAmount;
				printf("Enter amount to withdraw: ");
				scanf("%lf", &withdrawAmount);
				if (withdrawAmount > balance) {
					printf("Insufficient funds.\n");
				} else {
					balance -= withdrawAmount;
					printf("You have withdrawn: $%.2f\n", withdrawAmount);
				}
				break;
			}
			case 3: {
				double depositAmount;
				printf("Enter amount to deposit: ");
				scanf("%lf", &depositAmount);
				balance += depositAmount;
				printf("You have deposited: $%.2f\n", depositAmount);
				break;
			}
			case 4:
				printf("Thank you for using the ATM. Goodbye!\n");
				break;
			default:
				printf("Invalid choice. Please try again.\n");
		}
	} while (choice != 4);
    
	return 0;
}
