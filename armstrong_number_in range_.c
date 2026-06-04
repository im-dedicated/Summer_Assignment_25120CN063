#include <stdio.h>

int main() {
	int start, end, num, remainder, result;
	printf("Enter the range (start and end): ");
	scanf("%d %d", &start, &end);

	printf("Armstrong numbers between %d and %d are:\n", start, end);
	for(num = start; num <= end; num++) {
		result = 0;
		int temp = num;
		while(temp != 0) {
			remainder = temp % 10;
			result += remainder * remainder * remainder;
			temp /= 10;
		}
		if(result == num) {
			printf("%d ", num);
		}
	}
	return 0;
}
