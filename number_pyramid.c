#include <stdio.h>

int main() {
    int n = 5;
    int i, j, k;
    
    for (i = 1; i <= n; i++) {
        for (j = n; j > i; j--) {
            printf(" ");
        }
        
        for (k = 1; k <= i; k++) {
            printf("%d", k);
        }
        
        for (k = i - 1; k >= 1; k--) {
            printf("%d", k);
        }
        
        printf("\n");
    }
    
    return 0;
}
