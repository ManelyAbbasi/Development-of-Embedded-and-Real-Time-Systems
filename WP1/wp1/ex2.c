// (C) __Parisa Babaei, Manely Abbasi, Meis Salim, group: 17 __ (2024)
// Work package 1
// Exercise 2
// Submission code: 897654

// ------ Includes -----------------------

#include <stdio.h>   // The standard input/output library to use the printf function
#include <stdlib.h>  // The standard library to use the atoi function [converts a string into an integer]
#include <stdbool.h> // The bool library to use the bool type
#include <string.h>  // The string library to use the strcpy, strncat, and strlen functions
#include <ctype.h>   // The ctype library to use the isdigit, isalpha, and isupper functions

// ------ Defines ------------------------

#define MAX 100 // Define the maximum length of the string

// ------ Function declarations ----------

// Method to check if an argument is a number
bool isNumber(char *argument);

// Method to encrypt a string
void encrypt(char *string, int shiftNr);

// ------ Main ---------------------------

int main(int argc, char *argv[]) // Support command line arguments
{
    if (argc != 2)                                    // Check if the number of arguments is not 2
    {
        printf("Error: Wrong number of arguments\n"); // Print an error message to the console
        return 1;                                     // Return 1 to indicate an error
    }

    if (!isNumber(argv[1]))                           // Check if the second argument is not a number
    {
        printf("Error: Invalid number.");             // Print an error message to the console
        return 1;                                     // Return 1 to indicate an error
    }

    int shiftNr = atoi(argv[1]); // Save the first argument as an integer for the number of shifts
    shiftNr = shiftNr % 26;      // Calculate the number of shifts in the range 0-25 (26 letters in the alphabet)
    
    char string[MAX] = "";       // Declare a variable to store the string
    char character;              // Declare a variable to store the current character

    // Using getchar() instead of scanf() since scanf() fails to stop at EOF on some devices/compilers
    /*getchar() is a standard library function in C that reads a single character from the standard input stream (stdin). 
    It returns an integer value representing the ASCII value of the character read.
    If there are no characters available to be read, getchar() returns EOF (End of File), which is typically defined as -1.*/
    while ((character = getchar()) != EOF) // Loop through the input until the end of the file
    {
        if (character == '\n') // Check if the character is a newline
        {
            encrypt(string, shiftNr); // Encrypt the string
            strcpy(string, "");       // Reset the string
            printf("\n");             // Print a newline to the console
        } else {
            strncat(string, &character, 1); // Append the character to the string
        }
    }
    return 0; // Return 0 to indicate success
}

// ------ Function definitions -----------

// Method to check if an argument is a number
bool isNumber(char *argument)
{
    for (int i = 0; i < strlen(argument); i++) // Loop through the argument - strlen = calculates the length of a string
    {
        if (isdigit(argument[i]) == 0)         // Check if the character is not a number
        {
            return false; // return false to indicate that the argument is not a number
        }
    }
    return true;          // return true to indicate that the argument is a number
}

// Method to encrypt a string
void encrypt(char *string, int shiftNr)
{
    for (int i = 0; i < strlen(string); i++) // Loop through the string
    {
        char character = string[i];          // Declare a variable to store the character
        if (isalpha(character))              // Check if the character is a letter
        {
            if (isupper(character))              // Check if the character is uppercase
            {
                character = character + shiftNr; // Shift the character by the number of shifts
                if (character > 'Z')             // Check if the character is outside the uppercase range
                {
                    character = character - 26;  // Shift the character back into the uppercase range
                }
            }
            else                                 // Check if the character is lowercase
            {
                character = character + shiftNr; // Shift the character by the number of shifts
                if (character > 'z')             // Check if the character is outside the lowercase range
                {
                    character = character - 26;  // Shift the character back into the lowercase range
                }
            }
            printf("%c", character);            // Print the character to the console
        }
    }
}
