// (C) __Parisa Babaei, Manely Abbasi, Meis Salim, group: 17 __ (2024)
// Work package 1
// Exercise 4: Bin2Dec
// Submission code: 897654

// ------ Includes -----------------------

#include <stdio.h>   // The standard input/output library to use the printf function
#include <stdbool.h> // The bool library to use the bool type
#include <string.h>  // The string library to use the strlen and strcmp functions
#include <stdlib.h>  // The standard library to use the strtol function

// ------ Defines ------------------------

#define MAX 50       // Define the maximum length of the string of binary number

// ------ Function declarations ----------

// Method to check if an argument is a binary number between 0 and LONG_MAX
bool isValidBinary(char *argument);

// ------ Main ---------------------------

int main(int argc, char *argv[]) // Support command line arguments
{
    char *binary = malloc(MAX); // The pointer to store the binary string allocated in the memory

    if (argc < 2) // Check if there is no arguments. To run the program in a pipeline,
                  // the binary number should be read from the standard input
    {
        fgets(binary, MAX, stdin); // Get the binary number from the standard input

        char *firstWhitespace = strpbrk(binary, " \t\n"); // Find the first whitespace in the input
        if (firstWhitespace != NULL)                     // Check if any whitespace character is found
        {
            *firstWhitespace = '\0';    // Replace the first whitespace with a null character
        }
    }
    else if (argc == 2) // Check if there is one argument
    {
        if (strcmp(argv[1], "-h") == 0) // Check if the help argument is provided
        {
            // Print help message
            printf("Use \"bin2hec [binary number]\" to get the hexadecimal version of the given number.", argv[0]);
            return 0; // Return with success code 0
        }
        else          // Check if the binary number is provided as an argument
        {
            binary = argv[1]; // Set the binary string to the first argument
        }
    }
    else // Check if there is more than one argument
    {
        printf("Error: Too many arguments provided\n"); // Print error message
        return 1;                                       // Return 1 to indicate error
    }

    if (isValidBinary(binary) == false) // Check if the number is valid
    {
        printf("Error: Number should be binary and between 0 and %ld bits.\n", sizeof(long) * 8);
        return 2;  // Return with error code 2
    }

    int bytes = ((strlen(binary) - 1) / 8) + 1; // The variable to store the number of bytes needed, 
                                                // to store the binary number

    long hexadecimal = strtol(binary, NULL, 2); // convert the binary string to a long 
                                                // by using strtol function using base 2

    if (bytes == 1) // Check if the number is 1 byte
    {
        printf("%.2lx", hexadecimal); // Print the long as a hexadecimal number with 2 digits
    }
    else if (bytes == 2)              // Check if the number is 2 bytes
    {
        printf("%.4lx", hexadecimal); // Print the long as a hexadecimal number with 4 digits
    }
    else if (bytes == 3)              // Check if the number is 3 bytes
    {
        printf("%.6lx", hexadecimal); // Print the long as a hexadecimal number with 6 digits
    }
    else if (bytes == 4)              // Check if the number is 4 bytes
    {
        printf("%.8lx", hexadecimal); // Print the long as a hexadecimal number with 8 digits
    }

    printf("\n"); // Print a new line

    return 0;     // Return 0 to indicate success
}

// ------ Function definitions -----------

// Method to check if an argument is a binary number between 0 and LONG_MAX
bool isValidBinary(char *argument)
{
    int length = strlen(argument); // Create a variable to store the length of the argument

    for (int i = 0; i < length; i++) // Iterate through the argument
    {
        if (argument[i] != '0' && argument[i] != '1') // Check if the current character is not 0 or 1
        {
            return false; // Return false to indicate that the argument is not a binary number
        }
    }

    if (length > sizeof(long) * 8) // Check if the binary argument is more than LONG_MAX
    {
        return false; // Return false to indicate that the argument is too big to be stored in a long
    }

    return true; // Return true to indicate that the argument is a valid binary number
}
