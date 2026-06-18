#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;

    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0)
            a[pos++] = a[i];
    }

    while (pos < n)
        a[pos++] = 0;

    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i + 1 < n)
            putchar(' ');
    }

    return 0;
}
