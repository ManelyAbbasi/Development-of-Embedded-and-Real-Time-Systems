// (C) __Parisa Babaei, Manely Abbasi, Meis Salim group: 17 __ (2024)
// Work package 1
// Exercise 1
// Submission code: 897654

// ------ Includes -----------------------

#include <stdio.h> // The standard input/output library to use the printf and scanf functions

// ------ Main ---------------------------

int main()
{
    printf("Enter an integer:\n"); // Print a prompt to the console
    int number;                    // Declare an integer variable
    scanf("%d", &number); // Read an integer from the console
  
        switch (number)
        {                    // Check the value of the integer
        case 1:              // Check if the value is 1
            printf("One\n"); // Print a unique string to the console
            break;           // Break out of the switch statement

        case 2:              // Check if the value is 2
            printf("Two\n"); // Print a unique string to the console
            break;           // Break out of the switch statement

        case 3:                // Check if the value is 3
            printf("Three\n"); // Print a unique string to the console
            break;             // Break out of the switch statement

        case 4:               // Check if the value is 4
            printf("Four\n"); // Print a unique string to the console
            break;            // Break out of the switch statement

        case 5:               // Check if the value is 5
            printf("Five\n"); // Print a unique string to the console
            break;            // Break out of the switch statement

        default:              // Check if the value is not 1, 2, 3, 4 or 5
                              // If the entered number is not within the valid range, print an error message
            printf("Enter a number between 1 and 5.\n");
            return 1;         // Return 1 to indicate an error
        }

        return 0; // Return 0 to indicate success
    }
    
    

