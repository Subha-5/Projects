// Project 1: Number Guessing Game

// Problem: This is going to be fun!!  We will write a program that generates a random number and asks the player to guess it. If the player’s guess is higher than the actual number, the program displays “Lower number please.” Similarly, if the user’s guess is too low, the program prints “Higher number please.”

// When the user guesses the correct number, the program displays the number of guesses the player used to arrive at the number.

/*Hints:
Use loops
Use a random number generator.  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int number, guess, no_of_guesses = 0;
    srand(time(0));             //resets programming time to 0 to generate a new number when program is rerun ( when game is again played )
    number = rand() % 100 + 1;  //generates random number between 1 to 100
    
    // printf("The number is %d\n", number);

    //keep running the loop until the number is guessed
    do
    {
        printf("Guess the number between 1 to 100\n");
        scanf("%d", &guess);

        if (guess > number)
            printf("Lower number please!\n");
        else if (guess < number)
            printf("Higher number please!\n");
        else
            printf("You guessed it in %d attempts\n", no_of_guesses);
        no_of_guesses++;
    } while (guess != number);

    return 0;
}