// (C) __Parisa Babaei, Manely Abbasi, Meis Salim, group: 17 __ (2024)
// Work package 1
// Exercise 5
// Submission code: 897654

// ------ Includes -----------------------

#include <stdio.h>  // The standard input/output library to use printf
#include <stdlib.h> // The standard library to use the rand function
#include <time.h>   // The time library to use the time function

// ------ Defines ------------------------

#define MAX 100       // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers

// ------ Function declarations ----------

// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab);

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq);

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq);

// ------ Function definitions -----------

// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab)
{
    srand(time(NULL));            // Set the seed of the random number generator
    for (int i = 0; i < MAX; i++) // Loop through the table MAX times
    {
        tab[i] = rand() % MAXNUMBER; // Get a random number between 0 and MAXNUMBER and put it in the table
    }
}

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq)
{
    for (int i = 0; i < MAXNUMBER; i++) // Loop through the frequency table and set all values to 0
    {
        freq[i] = 0;
    }

    for (int i = 0; i < MAX; i++) // Loop through the table
    {
        int value = tab[i];       // Get the value of the current cell
        freq[value] += 1;         // Increase the frequency of that value
    }
}

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq)
{
    for (int i = 0; i < MAXNUMBER; i++)         // Loop through the frequency table
    {
        if (freq[i] > 0)                        // Check if the value exists in the table
        {
            int frequency = freq[i];            // Get the frequency of the current value

            printf("%d: ", i);                  // Print the value

            for (int j = 0; j < frequency; j++) // Loop through the frequency
            {
                printf("x");                    // Print an x for each frequency
            }

            printf("\n");                       // Print a new line after each value
        }
    }
}

// ------ Main ---------------------------
// The main entry point for the program
int main(void)
{
    int table[MAX];            // Create the table of random numbers
    int frequency[MAXNUMBER];  // Create the frequency table

    create_random(table);              // Create a set of random numbers

    printf("Table: ");                 // Print the table
    for (int i = 0; i < MAX; i++)      // Loop through the table
    {
        printf("%d ", table[i]);       // Print the current value
    }

    printf("\n");                      // Print a new line
    count_frequency(table, frequency); // Count the frequency of the random numbers
    draw_histogram(frequency);         // Draw the histogram
}
