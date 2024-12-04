// (C) __Parisa Babaei, Manely Abbasi, Meis Salim, group: 17 __ (2024)
// Work package 3
// Exercise 5
// Submission code: 040966

// ------ Includes -----------------------

#include <stdio.h>  // The standard input/output library to use the printf and scanf functions
#include <stdlib.h> // The standard library to use the rand function
#include <time.h>   // The time library to use the time function

// ------ Defines ------------------------

#define MAX 5       // Define the maximum length of the list

// ------ Main ---------------------------

int main() {
    srand(time(0));                     // Seed the random number generator
    int array[MAX];                     // Declare an array of integers with the maximum length
    int *ptr = array;                   // Set the pointer to the head of the array

    for (int i = 0; i < MAX; i++) {     // Loop through the array
        array[i] = rand() % 100;        // Set the value of the current integer to a random number between 0 and 99
    }

    // Print the address of the array by casting to a void pointer
    printf("The value of the address of the array (pointer) is: %p\n", (void *)ptr);
    // Print the first integer in the array by dereferencing the pointer
    printf("First integer in the array is (array[0]): %d\n", *ptr);
    // Print the last integer in the array by using array indexing
    printf("The last integer in the array is: %d\n", array[MAX - 1]);
    // Print the size of an integer
    printf("The size of an integer (number of bytes) is: %lu\n", sizeof(int));
    // Print the size of the whole array
    printf("The size of the whole array in bytes is: %lu\n", sizeof(array));

    for (int i = 0; i < MAX; i++) { // Loop through the array
        printf("value: %d, double: %d\n", *ptr, (*ptr) * 2); // Print the value and the double
        ptr++; // Move the pointer to the next integer
    }
}
