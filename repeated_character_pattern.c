#include <stdio.h>

int main(void) {
	int rows;

	printf("Enter number of rows: ");
	if (scanf("%d", &rows) != 1 || rows <= 0) return 0;

	for (int i = 0; i < rows; ++i) {
		char c = 'A' + i;
		for (int j = 0; j <= i; ++j) putchar(c);
		putchar('\n');
	}

	return 0;
}
