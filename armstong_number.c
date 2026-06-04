#include <stdio.h>

int main() {
	int num, original, remainder, result = 0;

	printf("Enter an integer: ");
	if (scanf("%d", &num) != 1) return 0;

	original = num;

	while (original != 0) {
		remainder = original % 10;
		result += remainder * remainder * remainder;
		original /= 10;
	}

	if (result == num)
		printf("%d is an Armstrong number\n", num);
	else
		printf("%d is not an Armstrong number\n", num);

	return 0;
}
