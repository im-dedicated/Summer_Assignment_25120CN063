#include <stdio.h>

int main(void) {
	long long n, original, rev = 0;
	int digit;

	if (printf("Enter an integer: ") < 0) return 0;
	if (scanf("%lld", &n) != 1) return 0;

	original = n;
	int negative = 0;
	if (n < 0) { negative = 1; n = -n; }

	while (n > 0) {
		digit = n % 10;
		rev = rev * 10 + digit;
		n /= 10;
	}

	if (negative) rev = -rev;

	printf("Original: %lld\nReversed: %lld\n", original, rev);
	return 0;
}

