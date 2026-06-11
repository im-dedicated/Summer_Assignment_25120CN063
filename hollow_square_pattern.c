#include <stdio.h>

int main(void) {
	int n;
	printf("Enter size: ");
	if (scanf("%d", &n) != 1 || n <= 0) return 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || i == n-1 || j == 0 || j == n-1)
				putchar('*');
			else
				putchar(' ');
		}
		putchar('\n');
	}

	return 0;
}
