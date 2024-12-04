// (C) __Parisa Babaei, Manely Abbasi, Meis Salim, group: 17 __ (2024)
// Work package 2
// Exercise 2
// Submission code: 1214663

// ------ Includes -----------------------

#include <stdio.h>  // The standard input/output library to use the printf and scanf functions
#include <stdlib.h> // The standard library to use the rand function
#include <time.h>   // The time library to use the time function

// ------ Defines ------------------------

#define MAX 5       // Define the maximum length of the list
#define NEW 42      // Define the number to add to the beginning of the list

// ------ typedefs -----------------------

typedef struct q        // Define the struct for the list
{
    int number;         // The number of the element
    struct q *next;     // The pointer to the next element
    struct q *prev;     // The pointer to the previous element
} REGTYPE;

// ------ Function declarations ----------

// Function to create a random linked list and return the pointer to the first element
REGTYPE *random_list(void);
// Function to add an element to the beginning of the linked list
REGTYPE *add_first(REGTYPE *temp, int data);

// ------ Main ---------------------------

int main(int argc, char *argv[])
{
    REGTYPE *act_post, *head = NULL;    // The pointers to the current and the first element
    srand(time(0));                     // Seed the random number generator
    head = random_list();               // Create a random linked list and set the pointer to the head
    act_post = head;                    // Set the pointer to the current element to the head
    int nr = 0;                         // The number of the current element
    while (act_post != NULL)            // Loop through the linked list
    {
        printf("\n Post nr %d : %d", nr++, act_post->number); // Print the number of the current element
        act_post = act_post->next;     // Set the pointer to the current element to the next element
    }

    printf("\n----------------");

    head = add_first(head, NEW);     // Add the new number to the beginning of the linked list
    act_post = head;                    // Set the pointer to the current element to the head
    nr = 0;                             // The number of the current element
    while (act_post != NULL)            // Loop through the linked list
    {
        printf("\n Post nr %d : %d", nr++, act_post->number); // Print the number of the current element
        act_post = act_post->next;     // Set the pointer to the current element to the next element
    }

    // --- Free the allocated memory ---
    while ((act_post = head) != NULL)  // Loop through the linked list
    {
        head = act_post->next;         // Set the pointer to the first element to the next element
        free(act_post);                // Free the memory of the current element
    }
    return 0;                          // Return 0 to indicate success
}

// ------ Function definitions -----------

// Function to create a random linked list and return the pointer to the first element
REGTYPE *random_list(void)
{
    int nr = 0;                        // The number of the current element
    REGTYPE *top, *item, *old = NULL;  // The pointers to the first, current and previous element
    for (int i = 0; i < MAX; i++)      // Loop through the linked list
    {
        nr = rand() % 100;             // Generate a random number
        if (old != NULL)               // Check if the previous element exists
        {
            item = malloc(sizeof(REGTYPE)); // Allocate memory for the current element
            item->number = nr;              // Set the number of the current element
            item->next = NULL;              // Set the pointer to the next element to NULL
            item->prev = old;               // Set the pointer to the previous element to old
            old->next = item;               // Set the pointer to the next element of old to the current element
            old = item;                     // Set the pointer to the previous element to the current element
        }
        else
        {
            top = malloc(sizeof(REGTYPE));  // Allocate memory for the first element
            top->number = nr;               // Set the number of the first element
            top->next = NULL;               // Set the pointer to the next element to NULL
            top->prev = NULL;               // Set the pointer to the previous element to NULL
            old = top;                      // Set the pointer to the previous element to the first element
        }
    }

    return (top);                          // Return the pointer to the first element
}

// Function to add an element to the beginning of the linked list
REGTYPE *add_first(REGTYPE *temp, int data)
{
    REGTYPE *top;                   // The pointer to the first element
    top = malloc(sizeof(REGTYPE));  // Allocate memory for the first element
    top->number = data;             // Set the number of the first element
    top->next = temp;               // Set the pointer to the next element to temp
    top->prev = NULL;               // Set the pointer to the previous element to NULL
    temp->prev = top;               // Set the pointer to the previous element of temp to top
    return (top);
}
