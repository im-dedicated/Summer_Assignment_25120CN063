#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isRotation(const char *s1, const char *s2) {
	int n1 = strlen(s1);
	int n2 = strlen(s2);
	if (n1 != n2) return 0;

	char *temp = (char *)malloc(n1 * 2 + 1);
	if (!temp) return 0;

    
	strcpy(temp, s1);
	strcat(temp, s1);


	int found = (strstr(temp, s2) != NULL);
	free(temp);
	return found;
}

int main(void) {
	char s1[201], s2[201];

	printf("Enter first string: ");
	if (scanf("%200s", s1) != 1) return 0;
	printf("Enter second string: ");
	if (scanf("%200s", s2) != 1) return 0;

	if (isRotation(s1, s2))
		printf("%s is a rotation of %s\n", s2, s1);
	else
		printf("%s is not a rotation of %s\n", s2, s1);

	return 0;
}
