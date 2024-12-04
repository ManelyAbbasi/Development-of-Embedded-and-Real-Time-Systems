// (C) __Parisa Babaei, Manely Abbasi, Meis Salim, group: 17 __ (2024)
// Work package 2
// Exercise 1
// Submission code: 1214663

// ------ Includes -----------------------

#include <stdio.h>   // The standard input/output library to use the printf and scanf functions
#include <stdlib.h>  // The standard library to use the atoi function
#include <stdbool.h> // The bool library to use the bool type
#include <ctype.h>   // The ctype library to use the isdigit function
#include <string.h>  // The string library to use the strlen function

// ------ Defines ------------------------

#define END 'e'      // Define the charachter to end the program
#define MAX 5        // Define the maximum length of the x and y input

// ------ typedefs -----------------------

enum DIRECTION // Define the enum for the direction of the robot
{
    N,
    E,
    S,
    W
};

typedef struct // Define the struct for the robot
{
    int xpos;           // The x position of the robot
    int ypos;           // The y position of the robot
    enum DIRECTION dir; // The direction of the robot of type DIRECTION
} ROBOT;

// ------ Function declarations ----------

// Method to move the robot one step in its direction
// It takes a pointer to the robot to change the xpos and ypos
void move(ROBOT *robot_ptr);

// Method to turn the robot 90 degrees in the same spot
// It takes a pointer to the robot to change the DIRECTION
void turn(ROBOT *robot_ptr);

// Method to reset the robot and run the game
void runRobot(ROBOT *robot_ptr);

// Method to empty the buffer of new lines and return the last char
char empty_buffer();

// Method to check if the input is a number between 0 and 99
bool isValidNumber(char *str);

// ------ Main ---------------------------

int main()
{
    ROBOT robot;                // Create a robot of type ROBOT
    ROBOT *robot_ptr = &robot;  // Create a pointer to the robot
    runRobot(robot_ptr);        // Run the robot
    return 0;                   // Return 0 to indicate success
}

// ------ Function definitions -----------

// Method to move the robot one step in its direction
// It takes a pointer to the robot to change the xpos and ypos
void move(ROBOT *robot_ptr)
{
    switch (robot_ptr->dir) // Switch on the direction of the robot
    {
    case N:                // If the direction is N
        robot_ptr->ypos++; // Increment the y position
        break;             // Break out of the switch
    case E:                // If the direction is E
        robot_ptr->xpos++; // Increment the x position
        break;             // Break out of the switch
    case S:                // If the direction is S
        robot_ptr->ypos--; // Decrement the y position
        break;             // Break out of the switch
    case W:                // If the direction is W
        robot_ptr->xpos--; // Decrement the x position
        break;             // Break out of the switch
    }
}

// Method to turn the robot 90 degrees in the same spot
// It takes a pointer to the robot to change the DIRECTION
void turn(ROBOT *robot_ptr)
{
    // Increment the direction and take the modulo 4 to loop around the direction
    robot_ptr->dir = (robot_ptr->dir + 1) % 4;
}

// Method to reset the robot and run the game
void runRobot(ROBOT *robot_ptr){
    robot_ptr->dir = N;  // Set the direction to N
    robot_ptr->xpos = 0; // Set the x position to 0
    robot_ptr->ypos = 0; // Set the y position to 0

    char x[5] = "";    // Char array to store the x position
    char y[5] = "";    // Char array to store the y position

    printf("Enter the starting x: "); // Prompt the user for the starting x
    scanf("%s", x);                   // Read the starting x

    if (!isValidNumber(x)) // Check if the input is not a number
    {
        printf("Invalid input\n"); // Print an error message
        return;                    // Return to end the program
    }

    printf("Enter the starting y: "); // Prompt the user for the starting y
    scanf("%s", y);                   // Read the starting y

    if (!isValidNumber(y)) // Check if the input is not a number
    {
        printf("Invalid input\n"); // Print an error message
        return;                    // Return to end the program
    }

    robot_ptr->xpos = atoi(x);          // Convert the x to an integer and store it in the robot
    robot_ptr->ypos = atoi(y);          // Convert the y to an integer and store it in the robot

    char instruction;                                  // Char to store the current instruction
    printf("Enter the instruction (or e to exit): ");  // Prompt the user for the instruction
    instruction = empty_buffer();                      // Empty the buffer of new lines and store the last char

    while (instruction != '\n') // Loop while the instruction is not a new line
    {
        switch (instruction)    // Switch on the instruction
        {
        case 'm':               // If the instruction is m
            move(robot_ptr);    // Move the robot
            break;              // Break out of the switch
        case 't':               // If the instruction is t
            turn(robot_ptr);    // Turn the robot
            break;              // Break out of the switch
        case END:               // If the instruction is END
            return;             // Return to end the program
        }
        instruction = getchar();        // Get the next instruction
    }

    // Print the final position of the robot
    printf("The final position is: (%d, %d)\n", robot_ptr->xpos, robot_ptr->ypos);

    // Print the final direction of the robot
    printf("The final direction is: ");

    switch (robot_ptr->dir) // Switch on the direction of the robot
    {
    case N:                 // If the direction is N
        printf("North");    // Print the final direction
        break;              // Break out of the switch
    case E:                 // If the direction is E
        printf("East");     // Print the final direction
        break;              // Break out of the switch
    case S:                 // If the direction is S
        printf("South");    // Print the final direction
        break;              // Break out of the switch
    case W:                 // If the direction is W
        printf("West");     // Print the final direction
        break;              // Break out of the switch
    }

    printf("\n");   // Print a new line

    runRobot(robot_ptr); // Run the robot again
}

// Method to empty the buffer of new lines and return the last char
char empty_buffer() {
    char c;                           // Char to store the last char
    while ((c = getchar()) == '\n');  // Empty the buffer of new lines
    return c;                         // Return the last char
}

// Method to check if the input is a number between 0 and 99
bool isValidNumber(char *str)
{
    for (int i = 0; i < strlen(str); i++) // Iterate over the characters in the string
    {
        if (isdigit(str[i]) == 0)         // Check if the character is not a number
        {
            return false;        // return false to indicate that the argument is not a number
        }
    }

    int num = atoi(str); // Convert the string to an integer

    if (num < 0 || num > 99) // Check if the argument is not between 1 and 99
    {
        return false; // return false to indicate that the argument is not a valid number
    }

    return true; // return true to indicate that the argument is a number
}
