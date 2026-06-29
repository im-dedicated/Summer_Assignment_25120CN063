#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 50

typedef struct {
	int id;
	char name[NAME_LEN];
	double balance;
	int active;
} Account;

static Account accounts[MAX_ACCOUNTS];
static int count = 0;

int find_account(int id) {
	for (int i = 0; i < count; i++) {
		if (accounts[i].active && accounts[i].id == id)
			return i;
	}
	return -1;
}

void create_account() {
	if (count >= MAX_ACCOUNTS) { printf("No more accounts can be created.\n"); return; }
	Account a;
	a.active = 1;
	printf("Enter account id (number): ");
	if (scanf("%d", &a.id) != 1) { while(getchar()!='\n'); printf("Invalid input\n"); return; }
	if (find_account(a.id) != -1) { printf("Account with this id already exists.\n"); return; }
	printf("Enter name: ");
	while (getchar() != '\n');
	if (!fgets(a.name, NAME_LEN, stdin)) a.name[0] = '\0';
	a.name[strcspn(a.name, "\n")] = '\0';
	printf("Enter initial deposit: ");
	if (scanf("%lf", &a.balance) != 1) { while(getchar()!='\n'); printf("Invalid amount\n"); return; }
	accounts[count++] = a;
	printf("Account created successfully.\n");
}

void deposit() {
	int id; double amt;
	printf("Enter account id: ");
	if (scanf("%d", &id) != 1) { while(getchar()!='\n'); printf("Invalid input\n"); return; }
	int idx = find_account(id);
	if (idx == -1) { printf("Account not found.\n"); return; }
	printf("Enter amount to deposit: ");
	if (scanf("%lf", &amt) != 1 || amt <= 0) { while(getchar()!='\n'); printf("Invalid amount\n"); return; }
	accounts[idx].balance += amt;
	printf("Deposit successful. New balance: %.2f\n", accounts[idx].balance);
}

void withdraw() {
	int id; double amt;
	printf("Enter account id: ");
	if (scanf("%d", &id) != 1) { while(getchar()!='\n'); printf("Invalid input\n"); return; }
	int idx = find_account(id);
	if (idx == -1) { printf("Account not found.\n"); return; }
	printf("Enter amount to withdraw: ");
	if (scanf("%lf", &amt) != 1 || amt <= 0) { while(getchar()!='\n'); printf("Invalid amount\n"); return; }
	if (accounts[idx].balance < amt) { printf("Insufficient funds.\n"); return; }
	accounts[idx].balance -= amt;
	printf("Withdrawal successful. New balance: %.2f\n", accounts[idx].balance);
}

void display_account() {
	int id;
	printf("Enter account id: ");
	if (scanf("%d", &id) != 1) { while(getchar()!='\n'); printf("Invalid input\n"); return; }
	int idx = find_account(id);
	if (idx == -1) { printf("Account not found.\n"); return; }
	Account *a = &accounts[idx];
	printf("Account id: %d\nName: %s\nBalance: %.2f\n", a->id, a->name, a->balance);
}

void list_accounts() {
	printf("\nAll accounts:\n");
	for (int i = 0; i < count; i++) {
		if (!accounts[i].active) continue;
		printf("%d - %s - %.2f\n", accounts[i].id, accounts[i].name, accounts[i].balance);
	}
}

int main(void) {
	int choice;
	while (1) {
		printf("\nBank System Menu:\n1. Create account\n2. Deposit\n3. Withdraw\n4. Display account\n5. List all\n6. Exit\nChoose: ");
		if (scanf("%d", &choice) != 1) { while(getchar()!='\n'); printf("Invalid choice\n"); continue; }
		switch (choice) {
			case 1: create_account(); break;
			case 2: deposit(); break;
			case 3: withdraw(); break;
			case 4: display_account(); break;
			case 5: list_accounts(); break;
			case 6: printf("Bye\n"); return 0;
			default: printf("Invalid option\n");
		}
	}
	return 0;
}
