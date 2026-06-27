#include<stdio.h>
#include<string.h>

int main(){
    char str1[100], str2[100];
    int i, j, found;
    
    printf("Enter first string: ");
    scanf("%s", str1);
    
    printf("Enter second string: ");
    scanf("%s", str2);
    
    printf("Common characters: ");
    
    for(i = 0; i < strlen(str1); i++){
        found = 0;
        for(j = 0; j < strlen(str2); j++){
            if(str1[i] == str2[j]){
                found = 1;
                break;
            }
        }
        if(found == 1){
            printf("%c ", str1[i]);
        }
    }
    
    printf("\n");
    return 0;
}