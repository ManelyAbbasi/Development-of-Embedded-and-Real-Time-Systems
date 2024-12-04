// (C) __Parisa Babaei, Manely Abbasi, Meis Salim, group: 17 __ (2024)
// Work package 2
// Exercise 3
// Submission code: 1214663

// ------ Includes -----------------------

#include <stdio.h>   // The standard input/output library to use the printf and scanf functions
#include <stdlib.h>  // The standard library to use the atoi function
#include <stdbool.h> // The standard boolean library to use the bool type
#include <string.h>  // The standard string library to use the strcpy, strlen and strcmp functions
#include <ctype.h>   // The standard character library to use the isdigit function

// ------ Defines ------------------------

#define FILENAME "people.dat" // The name of the binary file

// ------ typedefs -----------------------

typedef struct // Define the struct for the person
{
    char firstname[20];   // First name
    char famname[20];     // Family name
    char pers_number[13]; // yyyymmddnnnc
} PERSON;

// ------ Function declarations ----------

// Method to read a person from the console
PERSON input_record(void);

// Method to create a file and write the first record
void write_new_file(PERSON *inrecord);

// Method to print out all elements in the file
void printfile(void);

// Method to search for a person in the file by first name if it exists
void search_by_firstname(char *name);

// Method to search for a person in the file by family name if it exists
void search_by_famname(char *name);

// Method to append a new person to the file
void append_file(PERSON *inrecord);

// Method to check if the input is a number between 1 and 5
bool isValidNumber(char *str);

// Method to clear the input buffer
void clearBuffer(void);

// ------ Main ---------------------------

int main(void)
{
    PERSON person;                              // Create a dummy person of type PERSON
    PERSON *pperson = &person;                  // Create a pointer to the person
    strcpy(person.firstname, "Jane");           // Set the default value of the first name
    strcpy(person.famname, "Doe");              // Set the default value of the family name
    strcpy(person.pers_number, "111111111111"); // Set the default value of the personal number

    bool exit = false;      // Create a boolean to control the loop
    int choice;             // Create an integer to store the choice
    char choiceStr[5] = ""; // Create a string to store the choice before validation

    while (!exit) // Loop until the user chooses to exit
    {
        // Print the menu options
        printf("--------------------\n");
        printf("Choose one of the following:\n");
        printf("1 Create a new and delete the old file.\n");
        printf("2 Add a new person to the file.\n");
        printf("3 Search for a person in the file.\n");
        printf("4 Print out all in the file.\n");
        printf("5 Exit the program.\n");
        printf("--------------------\n");

        scanf(" %s", &choiceStr); // Read the choice from the console

        if (!isValidNumber(choiceStr)) // Check if the input is a number between 1 and 5
        {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            continue; // Skip the rest of the loop and start from the beginning
        }

        choice = atoi(choiceStr); // Convert the string to an integer

        switch (choice) // Switch on the choice
        {
        case 1:                      // If the choice is to create a new file
            write_new_file(pperson); // Call the method to create a new file
            break;                   // Break out of the switch

        case 2:                                // If the choice is to add a new person to the file
            PERSON newperson = input_record(); // Call the method to read a person from the console
            append_file(&newperson);           // Call the method to append the new person to the file
            break;                             // Break out of the switch

        case 3:            // If the choice is to search for a person in the file
            char name[20]; // Create a string to store the name
            int option;    // Create an integer to store the search type

            // Prompt the user to enter the search type
            printf("Choose the search type:\n");
            printf("1 Search by first name.\n");
            printf("2 Search by family name.\n");

            scanf(" %d", &option); // Read the choice from the console

            if (option == 1) // If the choice is to search by first name
            {
                printf("Enter the first name: "); // Prompt the user to enter the first name
                scanf(" %s", name);               // Read the first name from the input
                search_by_firstname(name);        // Call the method to search in the file by first name
            }
            else if (option == 2) // If the choice is to search by family name
            {
                printf("Enter the family name: "); // Prompt the user to enter the family name
                scanf(" %s", name);                // Read the family name from the input
                search_by_famname(name);           // Call the method to search in the file by family name
            }
            else // If the choice is invalid
            {
                printf("Invalid input.\n"); // Print a message to indicate that the input is invalid
            }
            clearBuffer(); // Clear the input buffer
            break;         // Break out of the switch

        case 4:          // If the choice is to print out all elements in the file
            printfile(); // Call the method to print out all elements in the file
            break;       // Break out of the switch

        case 5:                   // If the choice is to exit the program
            printf("Exiting.\n"); // Print a message to indicate that the program is exiting
            exit = true;          // Set the boolean to true to exit the loop
            break;                // Break out of the switch

        default:                        // This will never happen since the input is checked before the switch
            printf("Invalid input.\n"); // Print a message to indicate that the input is invalid
            break;                      // Break out of the switch
        }
    }

    return 0; // Return 0 to indicate success
}

// ------ Function definitions -----------

// Method to read a person from the console
PERSON input_record(void)
{
    PERSON person; // Create a person

    clearBuffer();                    // Clear the input buffer
    printf("Enter the first name: "); // Prompt the user to enter the first name
    scanf(" %19s", person.firstname); // Read the first name from the input

    clearBuffer();                     // Clear the input buffer
    printf("Enter the family name: "); // Prompt the user to enter the family name
    scanf(" %19s", person.famname);    // Read the family name from the input

    clearBuffer();                         // Clear the input buffer
    printf("Enter the personal number: "); // Prompt the user to enter the personal number
    scanf(" %12s", person.pers_number);    // Read the personal number from the input

    return person; // Return the person
}

// Method to create a file and write the first record
void write_new_file(PERSON *inrecord)
{
    FILE *file; // Create a file pointer to store the file

    file = fopen(FILENAME, "wb"); // Create a new file or overwrite an existing file in write/binary mode

    fwrite(inrecord, sizeof(PERSON), 1, file); // Write the first record to the file
    fclose(file);                              // Close the file
    printf("File created.\n");                 // Print a message to indicate that the file was created
}

// Method to print out all elements in the file
void printfile(void)
{
    FILE *file;      // Create a file pointer to store the file
    PERSON current;  // Create a person to store the current record
    int counter = 0; // Create a counter to store the number of records

    file = fopen(FILENAME, "rb"); // Open the file in read/binary mode

    if (file == NULL) // Check if the file could not be opened (e.g. does not exist)
    {
        printf("File does not exist.\n"); // Message to indicate that the file could not be opened
        return;                           // Return to the menu
    }

    while (fread(&current, sizeof(PERSON), 1, file)) // Read the next record from the file
    {
        counter++;                                            // Increment the counter
        printf("--------------------\n");                     // Print a separator
        printf("Record number: %d\n", counter);               // Print the record number
        printf("First name: %s\n", current.firstname);        // Print the first name
        printf("Family name: %s\n", current.famname);         // Print the family name
        printf("Personal number: %s\n", current.pers_number); // Print the personal number
    }

    if (counter == 0) // Check if the counter is 0
    {
        printf("The file is empty.\n"); // Print a message to indicate that the file is empty
    }

    fclose(file); // Close the file
}

// Method to search for a person in the file by first name if it exists
void search_by_firstname(char *name)
{
    FILE *file;           // Create a file pointer to store the file
    PERSON current;       // Create a person to store the current record
    int counter = 0;      // Create a counter to store the number of records
    bool isFound = false; // Create a boolean to check if a match is found

    file = fopen(FILENAME, "rb"); // Open the file in read/binary mode

    if (file == NULL) // Check if the file could not be opened (e.g. does not exist)
    {
        printf("File does not exist.\n"); // Message to indicate that the file could not be opened
        return;                           // Return to the menu
    }

    while (fread(&current, sizeof(PERSON), 1, file)) // Read the next record from the file
    {
        counter++; // Increment the counter
        if (strcmp(current.firstname, name) == 0)
        {
            printf("Found a match!\n");                           // Message to indicate success
            printf("First name: %s\n", current.firstname);        // Print the first name
            printf("Family name: %s\n", current.famname);         // Print the family name
            printf("Personal number: %s\n", current.pers_number); // Print the personal number
            isFound = true;
            break;
        }
    }

    if (counter == 0) // Check if the counter is 0
    {
        printf("The file is empty.\n"); // Print a message to indicate that the file is empty
    }
    else if (!isFound)
    {                                       // Check if no matches were found
        printf("No matches were found.\n"); // Print a message to indicate that no match was found
    }

    fclose(file); // Close the file
}

// Method to search for a person in the file by family name if it exists
void search_by_famname(char *name)
{
    FILE *file;           // Create a file pointer to store the file
    PERSON current;       // Create a person to store the current record
    int counter = 0;      // Create a counter to store the number of records
    bool isFound = false; // Create a boolean to check if a match is found

    file = fopen(FILENAME, "rb"); // Open the file in read/binary mode

    if (file == NULL) // Check if the file could not be opened (e.g. does not exist)
    {
        printf("File does not exist.\n"); // Message to indicate that the file could not be opened
        return;                           // Return to the menu
    }

    while (fread(&current, sizeof(PERSON), 1, file)) // Read the next record from the file
    {
        counter++; // Increment the counter
        if (strcmp(current.famname, name) == 0)
        {
            printf("Found a match!\n");                           // Message to indicate success
            printf("First name: %s\n", current.firstname);        // Print the first name
            printf("Family name: %s\n", current.famname);         // Print the family name
            printf("Personal number: %s\n", current.pers_number); // Print the personal number
            isFound = true;
            break;
        }
    }

    if (counter == 0) // Check if the counter is 0
    {
        printf("The file is empty.\n"); // Print a message to indicate that the file is empty
    }
    else if (!isFound)
    {                                       // Check if no matches were found
        printf("No matches were found.\n"); // Print a message to indicate that no match was found
    }

    fclose(file); // Close the file
}

// Method to append a new person to the file
void append_file(PERSON *inrecord)
{
    FILE *file; // Create a file pointer to store the file

    file = fopen(FILENAME, "rb"); // Open the file in read/binary mode

    if (file == NULL) // Check if the file could not be opened (e.g. does not exist)
    {
        printf("File does not exist.\n"); // Message to indicate that the file could not be opened
        return;                           // Return to the menu
    }

    fclose(file); // Close the file

    file = fopen(FILENAME, "ab"); // Open the file in append/binary mode

    fwrite(inrecord, sizeof(PERSON), 1, file); // Write the first record to the file

    fclose(file); // Close the file

    printf("Record added.\n"); // Print a message to indicate that the record was added
}

// Method to check if an argument is a number between 1 and 5
bool isValidNumber(char *argument)
{
    for (int i = 0; i < strlen(argument); i++) // Iterate over the characters in the argument
    {
        if (isdigit(argument[i]) == 0) // Check if the character is not a number
        {
            return false; // return false to indicate that the argument is not a number
        }
    }

    int num = atoi(argument); // Convert the argument to an integer

    if (num < 1 || num > 5) // Check if the argument is not between 1 and 5
    {
        return false; // return false to indicate that the argument is not a valid number
    }

    return true; // return true to indicate that the argument is a valid number
}

// Method to clear the input buffer
void clearBuffer(void)
{
    while (getchar() != '\n')
        ; // Clear the input buffer
}
