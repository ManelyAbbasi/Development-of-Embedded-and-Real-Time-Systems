// (C) __Parisa Babaei, Manely Abbasi, Meis Salim, group: 17 __ (2024)
// Work package 0
// Exercise 1-3
// Submission code: 482960 (provided by your TA-s)

// Include section
#include <stdio.h>

// Main function in the program, supports command line arguments
// argc is number of arguments, argv[] points to argument
int main (int argc, char *argv[]) {
    // Check if the number of arguments is less than 2
    if (argc < 2) {
        // Print an error message
        printf("Error: Too few arguments\n");
        // Print -h for help
        printf("Use \"wp0.exe -h\" to get help with running the program");
        // Return 1 to indicate an error
        return 1;
    }
    // Check if the number of arguments is more than 2
    if (argc > 2) {
        // Print an error message
        printf("Error: Too many arguments\n");
        // Print -h for help
        printf("Use \"wp0.exe -h\" to get help with running the program");
        // Return 1 to indicate an error
        return 1;
    }
    // Check if the user asked for help
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        // Print help messages
        printf("The command \"wp0.exe <name>\" prints \"Hello World! - I'm <name>!\"");
        // Return 0 to indicate success
        return 0;
    }

/*
    // If condition checks if argc is more than one AND if the argv input is "-h"
    (help), then the following line is printed.
    if (argc > 1 && strcmp(argv[1], "-h") == 0) {
    printf("Rerun the program and input name as argument for the program to
    output Hello World!\n");
    //return 0 after each if statement
    return 0;
    }
*/
    // Print a string to the console
    printf("Hello World! - I'm %s!", argv[1]); // Note: double quotes
    // Return 0 to indicate success
    return 0;
}