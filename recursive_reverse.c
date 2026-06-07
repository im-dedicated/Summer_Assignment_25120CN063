#include <stdio.h>

void rev_print(int n)
{
	if (n < 0) { // handle negative numbers
		putchar('-');
		n = -n;
	}
	if (n < 10) {
		printf("%d", n);
		return;
	}
	printf("%d", n % 10);
	rev_print(n / 10);
}

int main(void)
{
	int num;
	if (printf("Enter an integer: ") && scanf("%d", &num) == 1) {
		printf("Reversed: ");
		rev_print(num);
		putchar('\n');
	} else {
		printf("Invalid input\n");
	}
	return 0;
}
