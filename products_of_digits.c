#include <stdio.h>
#include <stdlib.h>

int product_of_digits(long n) {
	if (n == 0) return 0;
	if (n < 0) n = -n;
	int prod = 1;
	while (n > 0) {
		prod *= (int)(n % 10);
		n /= 10;
	}
	return prod;
}

int main(void) {
	char buf[64];
	long num;
	printf("Enter an integer: ");
	if (!fgets(buf, sizeof buf, stdin)) return 0;
	char *endptr;
	num = strtol(buf, &endptr, 10);
	if (endptr == buf || (*endptr != '\n' && *endptr != '\0')) {
		printf("Invalid input\n");
		return 0;
	}
	printf("Product of digits = %d\n", product_of_digits(num));
	return 0;
}

