// (C) __Parisa Babaei, Manely Abbasi, Meis Salim, group: 17 __ (2024)
// Work package 3
// Exercise 6
// Submission code: 040966

// ------ Includes -----------------------

#include <stdio.h>  // The standard input/output library for printf
#include <string.h> // The string library for strlen and strcpy

// ------ Function declarations ----------

// Custom function to copy a string
void copyString(char *original, char *copy);

// ------ Main ---------------------------

int main() {
    char input[21];    // Declare a character array to store the input
    char copyOne[21];  // Declare a character array to store the copy
    char copyTwo[21];  // Declare a character array to store the copy
    
    printf("Enter a string (max 20 characters): "); // Prompt the user for input
    fgets(input, 21, stdin); // Read a string from the standard input

    int length = strlen(input); // Get the length of the string

    if (input[length - 1] == '\n') { // Check if the last character is a newline
        input[length - 1] = '\0';    // Remove the newline character
    }

    copyString(input, copyOne);           // Call the custom function to copy the string
    printf("Custom Copy: %s\n", copyOne); // Print the copy

    strcpy(copyTwo, input);                 // Call the custom function to copy the string
    printf("Strcpy Copy: %s\n", copyTwo);   // Print the copy

    return 0; // Return 0 to indicate that the program has finished
}

// ------ Function definitions -----------

// Custom function to copy a string
void copyString(char *original, char *copy) {
    while (*original) {     // Loop through the original string
        *copy = *original;  // Copy the character
        original++;         // Move the pointer to the next character
        copy++;             // Move the pointer to the next character
    }
    *copy = '\0';           // Add the null terminator to the end of the copy
}
