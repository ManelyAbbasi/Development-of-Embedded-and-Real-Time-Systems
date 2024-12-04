// (C) __Parisa Babaei, Manely Abbasi, Meis Salim, group: 17 __ (2024)
// Work package 2
// Exercise 4
// Submission code: 1214663

// ------ Includes -----------------------

#include <stdio.h> // The standard input/output library to use the printf and scanf functions
#include <string.h> // The string library to use the strlen function
#include <ctype.h> // The character type library to use the toupper function

// ------ Function declarations ----------

// Method to print the decoded byte
void printDecode(char byte);

// ------ Main ---------------------------

int main(int argc, char *argv[]) // Main method, supports command line arguments
{
    if (argc != 2) // Check if the number of arguments is correct
    {
        printf("The number of arguments is not correct\n"); // Print an error message
        return 1;                                           // Return 1 to indicate an error
    }

    if (strlen(argv[1]) != 2) // Check if the length of the input string is not 2
    {
        printf("The length of the input string is not correct\n"); // Print an error message
        return 1;                                                  // Return 1 to indicate an error
    }

    char* hexAlphabet = "0123456789ABCDEF"; // The hexadecimal alphabet
    char byte = 0;                          // The byte to be printed

    for (int i = 0; i < 2; i++) // Iterate over the argument string
    {
        char c = toupper(argv[1][i]); // Get the char at the i position and convert it to uppercase
        int index = -1;               // The index of the character in the hexadecimal alphabet

        for (int j = 0; j < 16; j++) // Iterate over the hexadecimal alphabet
        {
            if (c == hexAlphabet[j]) // Check if the character is found
            {
                index = j; // Set the index of the character
                break;     // Break the loop
            }
        }

        if (index == -1) // Check if the character is not found
        {
            printf("The string contains an invalid character\n"); // Print an error message
            return 1;                                             // Return 1 to indicate an error
        }

        byte = (byte << 4) | index; // Shift the byte 4 bits to the left and add the index
    }

    printDecode(byte); // Print the decoded byte

    return 0; // Return 0 to indicate success
}

// ------ Function definitions -----------

// Method to print the decoded byte
void printDecode(char byte)
{
    printf("Name          Value\n");
    printf("-----------------------------\n");
    // Get the bit at position 7 by shifting and using the bitwise AND operator with 0b1
    printf("engine_on     %d\n", (byte >> 7) & 1);
    // Get the bit at position 7 by shifting and using the bitwise AND operator with 0b111
    printf("gear_pos      %d\n", (byte >> 4) & 7);
    // Get the bit at position 7 by shifting and using the bitwise AND operator with 0b11
    printf("key_pos       %d\n", (byte >> 2) & 3);
    // Get the bit at position 7 by shifting and using the bitwise AND operator with 0b1
    printf("brake1        %d\n", (byte >> 1) & 1);
    // Get the bit at position 7 by shifting and using the bitwise AND operator with 0b1
    printf("brake2        %d\n", byte & 1);
}
