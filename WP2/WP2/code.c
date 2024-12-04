// (C) __Parisa Babaei, Manely Abbasi, Meis Salim, group: 17 __ (2024)
// Work package 2
// Exercise 4
// Submission code: 1214663

// ------ Includes -----------------------

#include <stdio.h> // The standard input/output library to use the printf and scanf functions
#include <stdlib.h> // The standard library to use the atoi function

// ------ Function declarations ----------

// Method to print the byte in hexadecimal
void printInHex(char byte);

// ------ Main ---------------------------

int main(int argc, char *argv[]) // Main method, supports command line arguments
{
    if (argc != 6) // Check if the number of arguments is correct
    {
        printf("The number of arguments is not correct\n"); // Print an error message
        return 1;                                           // Return 1 to indicate an error
    }

    int engine_on = atoi(argv[1]); // Convert the first argument to an integer

    if (engine_on != 0 && engine_on != 1)               // Check if the value is not in range 0..1
    {
        printf("The engine_on value is not correct\n"); // Print an error message
        return 1;                                       // Return 1 to indicate an error
    }

    int gear_pos = atoi(argv[2]); // Convert the second argument to an integer

    if (gear_pos < 0 || gear_pos > 4)                   // Check if the value is not in range 0..4
    {
        printf("The gear_pos value is not correct\n");  // Print an error message
        return 1;                                       // Return 1 to indicate an error
    }

    int key_pos = atoi(argv[3]); // Convert the third argument to an integer

    if (key_pos < 0 || key_pos > 2)                     // Check if the value is not in range 0..2
    {
        printf("The key_pos value is not correct\n");   // Print an error message
        return 1;                                       // Return 1 to indicate an error
    }

    int brake1 = atoi(argv[4]); // Convert the fourth argument to an integer

    if (engine_on != 0 && engine_on != 1)              // Check if the value is not in range 0..1
    {
        printf("The brake1 value is not correct\n");   // Print an error message
        return 1;                                      // Return 1 to indicate an error
    }

    int brake2 = atoi(argv[5]); // Convert the fifth argument to an integer

    if (engine_on != 0 && engine_on != 1)             // Check if the value is not in range 0..1
    {
        printf("The brake2 value is not correct\n");  // Print an error message
        return 1;                                     // Return 1 to indicate an error
    }

    char byte = 0; // Create a byte and set it to 0

    // Set the bits of the byte according to the input values
    // Move the bits to the correct position and use the bitwise OR operator to set the bits
    byte = byte | (engine_on << 7); // Set the leftmost bit
    byte = byte | (gear_pos << 4);  // Set the bits from the 5th to the 7th
    byte = byte | (key_pos << 2);   // Set the bits from the 3rd to the 4th
    byte = byte | (brake1 << 1);    // Set the 2nd bit from the right
    byte = byte | brake2;           // Set the rightmost bit

    printInHex(byte); // Call the method to print the byte in hexadecimal

    return 0; // Return 0 to indicate success
}

// ------ Function definitions -----------

// Method to print the byte in hexadecimal
void printInHex(char byte)
{
    char* hexAlphabet = "0123456789ABCDEF"; // The hexadecimal alphabet

    // Shift the byte 4 bits to the right and use bitwise AND with 0x0F (which is 00001111 in binary) 
    // to get the first digit of the byte in hexadecimal
    int firstDigit = (byte >> 4) & 0x0F; 

    // Use bitwise AND with 0x0F to get the second digit of the byte in hexadecimal
    int secondDigit = byte & 0x0F;

    printf("The byte in hexadecimal is: ");

    // Print the first digit by using it as an index in the hexadecimal alphabet
    printf("%c", hexAlphabet[firstDigit]);

    // Print the second digit by using it as an index in the hexadecimal alphabet
    printf("%c", hexAlphabet[secondDigit]);

    printf("\n");
}
