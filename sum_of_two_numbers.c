#include <stdio.h>

int sum(int a, int b) {
	return a + b;
}

int main(void) {
	int x, y;

	if (scanf("%d %d", &x, &y) != 2) {
		return 1;
	}

	int s = sum(x, y);
	printf("%d\n", s);
	return 0;
}
