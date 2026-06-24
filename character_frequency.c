#include <stdio.h>
#include <string.h>

int main(void)
{
	char line[1001];
	int freq[256] = {0};
	int i;

	printf("Enter a line of text (max 1000 chars):\n");
	if (!fgets(line, sizeof(line), stdin))
		return 0;

	for (i = 0; line[i] != '\0'; ++i) {
		unsigned char c = (unsigned char)line[i];
		if (c == '\n')
			continue;
		freq[c]++;
	}

	printf("\nCharacter frequencies:\n");
	for (i = 0; i < 256; ++i) {
		if (freq[i] == 0) continue;
		if (i >= 32 && i <= 126)
			printf("'%c' : %d\n", i, freq[i]);
		else
			printf("0x%02X : %d\n", i, freq[i]);
	}

	return 0;
}
