#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int secret, guess, tries;
    
    srand(time(0));
    secret = rand() % 100 + 1;
    tries = 0;
    
    printf("Welcome to Number Guessing Game\n");
    printf("I have chosen a number between 1 and 100\n");
    printf("Try to guess it!\n\n");
    
    while(1)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;
        
        if(guess == secret)
        {
            printf("Correct! You found it in %d tries\n", tries);
            break;
        }
        else if(guess < secret)
        {
            printf("Too low, try again\n\n");
        }
        else
        {
            printf("Too high, try again\n\n");
        }
    }
    
    return 0;
}
