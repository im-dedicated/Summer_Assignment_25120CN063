#include <stdio.h>

int main() {
	int n1, n2;
	printf("Enter size of first array: ");
	if (scanf("%d", &n1) != 1 || n1 <= 0) return 0;
	int a[n1];
	printf("Enter %d elements of first array:\n", n1);
	for (int i = 0; i < n1; i++) scanf("%d", &a[i]);

	printf("Enter size of second array: ");
	if (scanf("%d", &n2) != 1 || n2 <= 0) return 0;
	int b[n2];
	printf("Enter %d elements of second array:\n", n2);
	for (int i = 0; i < n2; i++) scanf("%d", &b[i]);

	int unionArr[n1 + n2];
	int k = 0;

	for (int i = 0; i < n1; i++) {
		unionArr[k++] = a[i];
	}

    
	for (int i = 0; i < n2; i++) {
		int found = 0;
		for (int j = 0; j < k; j++) {
			if (b[i] == unionArr[j]) { found = 1; break; }
		}
		if (!found) unionArr[k++] = b[i];
	}

	printf("Union of arrays: ");
	for (int i = 0; i < k; i++) printf("%d ", unionArr[i]);
	printf("\n");

	return 0;
}
