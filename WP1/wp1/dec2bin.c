// (C) __Parisa Babaei, Manely Abbasi, Meis Salim, group: 17 __ (2024)
// Work package 1
// Exercise 4: Dec2Bin
// Submission code: 897654

// ------ Includes -----------------------

#include <stdio.h>   // The standard input/output library to use the printf function
#include <stdlib.h>  // The standard library to use the atol function
#include <stdbool.h> // The bool library to use the bool type
#include <string.h>  // The string library to use the strlen and strcmp functions
#include <ctype.h>   // The ctype library to use the isdigit function
#include <limits.h>  // The limits library to use the LONG_MAX constant

// ------ Function declarations ----------

// Method to check if an argument is a decimal number between 0 and LONG_MAX
bool isValidDecimal(char *argument);

// ------ Main ---------------------------

int main(int argc, char *argv[]) { // Support command line arguments
    if (argc != 2) {                                  // Check if the number of arguments is not correct
        printf("Error: Wrong number of arguments\n"); // Print error message
        return 1;                                     // Return with error code 1
    }

    if (strcmp(argv[1], "-h") == 0) { // Check if the help argument is provided
        // Print help message
        printf("Use \"dec2bin [decimal number]\" to get the binary version of the given number.", argv[0]);
        return 0; // Return with success code 0
    }

    if (isValidDecimal(argv[1]) == false){                          // Check if the number is valid
        printf("Error: Number should be between 0 and %ld.\n", LONG_MAX); // Print error message
        return 2;                                                         // Return with error code 2
    }

    long decimal = atol(argv[1]); // Convert the string to a long
    int bitsNr;                    // The variable to store the number of binary digits

    if (decimal <= 257) {             // Check if the number is 1 byte
        bitsNr = 8;                   // Set the number of bits to 8
    } else if (decimal <= 65537) {    // Check if the number is 2 bytes
        bitsNr = 16;                  // Set the number of bits to 16
    } else if (decimal <= 16777217) { // Check if the number is 3 bytes
        bitsNr = 24;                  // Set the number of bits to 24
    } else {                          // Check if the number is 4 bytes
        bitsNr = 32;                  // Set the number of bits to 32
    }

    int bit; // Create a variable to store the last calculated bit

    for (int i = bitsNr - 1; i >= 0; i--) { // Iterate through the binary number bit by bit
        bit = decimal >> i; // Calculate the bit at the leftmost position
                            // by shifting the decimal number by i
                            // this will move the bit at the i-th position to the rightmost position

        if (bit & 1) {      // Check if the bit is 1 or 0 by using the bitwise AND operator with 1
            printf("1");    // Print 1
        } else {
            printf("0");    // Print 0
        }
    }

    printf("\n"); // Print a new line

    return 0;     // Return with success code 0
}

// ------ Function definitions -----------

// Method to check if an argument is a decimal number between 0 and LONG_MAX
bool isValidDecimal(char *argument)
{
    for (int i = 0; i < strlen(argument); i++) // Iterate through the characters of the argument
    {
        if (isdigit(argument[i]) == 0)      // Check if the character is not a number
        {
            return false;               // return false to indicate that the argument is not a number
        }
    }

    if (atol(argument) < 0 || atol(argument) > LONG_MAX) // Check if the argument is not between 0 and LONG_MAX
    {
        return false; // return false to indicate that the argument is not valid
    }

    return true; // return true to indicate that the argument is valid
}
