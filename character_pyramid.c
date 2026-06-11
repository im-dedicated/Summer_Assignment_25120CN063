#include <stdio.h>

int main(void) {
	int n = 5;
	for (int i = 1; i <= n; ++i) {
		for (int s = 0; s < n - i; ++s) putchar(' ');

		for (int k = 0; k < i; ++k) putchar('A' + k);

		for (int k = i - 2; k >= 0; --k) putchar('A' + k);

		putchar('\n');
	}
	return 0;
}
