// Include section
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For using rand() and srand() functions.
#include <time.h>   // For using the time_t variable.

// Define section
#define MAX_NUMBER 10 // Maximum number of guesses is defined as 10.

// Main program section
// Program logic
int main()
{
    // Declaration and initialization of variables that will be used.
    int secretNum, guessNum, numOfGuess = 0;
    // Used at the end of each round.
    char restart[10];
    time_t t1;

    // Here we use the time variable and srand() function to create a random number.
    srand((unsigned)time(&t1));
    // This makes sure the random number is between 1 and 100.
    secretNum = (rand() % 100) + 1;
    printf("Hello! I will now think of a number...\n");
    printf("The number is between 1 and 100...\n");
    printf("CAN YOU GUESS IT IN 10 TRIES?!\n");
    // This message is printed at the beginning of program execution.
    // If this message is displayed - the program either just started, or has restarted with a new random number.

    do
    {
        // Do-While loop that executes while the user tries to guess the number.
        scanf("%d", &guessNum);
        if (guessNum < 1 || guessNum > 100)
        {
            // If the guess if outside 1-100, this message is displayed and the program restarts with a new number.
            printf("Remember, the secret number is between 1 and 100. Let's tryagain...\n");
            break;
        }
        // The loop ends if the user has made over 10 guesses.
        else if (numOfGuess == MAX_NUMBER)
        {
            printf("Exceeded number of guesses!\n");
            break;
        }
        else if (guessNum == secretNum)
        {
            // If the guessed number is correct, a total number of guesses is displayed and the loop ends.
            numOfGuess++;
            printf("You have guessed %d times and your guess is correct!\n", numOfGuess);
        }

        else if (guessNum < secretNum)
        {
            // If guessed number is under the secret number, user is prompted toguess a new value and sees total number of guesses so far.
            numOfGuess++;
            printf("Your guess is too low! Try again... ");
            printf("\nTotal number of guesses: %d\n", numOfGuess);
        }
        else
        {
            // If guessed number is over the secret number, user is prompted to guess a new value and sees total number of guesses so far.
            numOfGuess++;
            printf("Your guess is too high! Try again...\n");
            printf("Total number of guesses: %d\n", numOfGuess);
        }

        // The loop ends when the guessed number is equal to the secret number.
    } while (guessNum != secretNum);

        // When a round is over, user can either restart or end the program.
        printf("Would you like to start over? Enter yes or no:\n");
    scanf("%s", restart);
    if (strcmp(restart, "yes") == 0)
    {
        // If user input is equal to "yes", the main() function is called and the program restarts.
        main();
    }
    else if (strcmp(restart, "no") == 0)
    {
        // If user input is equal to "no", the program is finished.
        printf("Finished.");
    }
    else
    {
        // For any other user input, the program is finished.
        printf("Finished.");
    }

    return 0;
}