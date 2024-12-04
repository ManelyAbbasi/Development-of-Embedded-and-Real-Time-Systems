// (C) __Parisa Babaei, Manely Abbasi, Meis Salim, group: 17 __ (2024)
// Work package 4
// Exercise 4
// Submission code: 639965 

// ------ Includes -----------------------

#include <stdio.h> // The standard I/O library for printf

// ------ Function declarations ----------

// Method to search for a number in an array using binary search
//int binary_search_number(int number, int tab[], int size);

// Method to search for a number in an array linearly
int search_number(int number, int tab[], int size);

// Method to sort an array
void sort(int number, int tab []);

// ------ Main ---------------------------

int main()
{
    int test[] = {1,2,34,5,67,3,23,12,13,10};   // Test array
    int size = 10;                              // Size of the test array
    int number = 13;                            // Number to search for
    int index;                                  // index of the number
    
    for (int i = 0; i < size; i++) // loop for the number of elements
    {
        printf("%d ", test[i]); // print the current element
    }
    printf("\n"); // print a new line


    index = search_number(number, test, size); // search for the number in the array
    // print the result of the search
    printf("The number %d is found at index %d using linear search\n", number, index);

    sort(size, test); // sort the array
    for (int i = 0; i < size; i++) // loop for the number of elements
    {
        printf("%d ", test[i]); // print the current element
    }
    printf("\n"); // print a new line

    //index = binary_search_number(number, test, size); // search for the number in the array
    // print the result of the search
    //printf("The number %d is found at index %d using binary search\n", number, index);

    return 0; // return 0 to indicate success
}

// ------ Function definitions -----------
/*
// Method to search for a number in an array using binary search
int binary_search_number(int number, int tab[], int size)
{
    int start = 0;      // start index
    int end = size - 1; // end index
    int first = -1;     // index of the first position of the number
    int mid;            // middle index
    while (start <= end)   // loop until the start index is bigger than the end index
    {
        mid = (start + end) / 2; // calculate the middle index
        if (tab[mid] == number) // if the middle element is the number
        {
            first = mid;    // set the first index to the middle index
            end = mid - 1;  // set the end index to the middle index - 1
        }
        else if (tab[mid] < number) // if the middle element is less than the number
        {
            start = mid + 1; // set the start index to the middle index + 1
        }
        else // if the middle element is bigger than the number
        {
            end = mid - 1; // set the end index to the middle index - 1
        }
    }

    return first; // return the index of the first position of the number
}
*/
// Method to search for a number in an array linearly
int search_number(int number, int tab[], int size)
{
    for (int i = 0; i < size; i++) // loop for the number of elements
    {
        if (tab[i] == number) // if the current element is the number
        {
            return i; // return the index of the current element
        }
    }
    return -1; // return -1 if the number is not found
}

// Method to sort an array
void sort(int number, int tab [])
{
    int min; // index of the minimum element
    int temp; // temporary variable for swapping
    for (int i = 0; i < number - 1; i++) // loop for the number of elements
    {
        min = i; // set the minimum index to the current index
        for (int j = i + 1; j < number; j++) // loop for the remaining elements
        {
            if (tab[j] < tab[min]) // if the current element is less than the minimum element
            {
                min = j; // set the minimum index to the current index
            }
        }
        temp = tab[i];     // Save the current element in a temporary variable
        tab[i] = tab[min]; // Set the current element to the minimum element
        tab[min] = temp;   // Set the minimum element to the current element
    }
}
