// Include section
#include <stdio.h>  // Include standard input/output library
#include <stdlib.h> // Include standard library for functions like malloc() and free()

// Define a structure for a node in a linked list
typedef struct Node
{
    // Value stored in the node
    int value;
    // Pointer to the next node in the linked list
    struct Node *next;
} Node;

// Function declarations
Node *createNode(int value);                 // Function to create a new node
void appendNode(Node **head, int value);     // Function to append a node to the end of the linked list
void calculateFibonacci(Node **head, int n); // Function to calculate Fibonacci numbers and store them in the linked list
void printFibNumber(Node *head, int n);      // Function to print the nth Fibonacci number
void addNode(Node **head, int value);        // Function to add a node to the end of the linked list

// Main section
int main(int argc, char *argv[])
{
    // Check if the correct number of command-line arguments is provided
    if (argc != 2)
    {
        printf("Usage: %s <Fibonacci number>\n", argv[0]);
        return 0;
    }

    int n;
    // Convert the command-line argument to an integer
    n = atoi(argv[1]);

    // Check if the input is negative, if so, print 0 and exit
    if (n < 0)
    {
        printf("0\n");
        return 0;
    }

    // Pointer to the head of the linked list
    Node *head;
    // Initialize head to NULL
    head = NULL;

    // Calculate Fibonacci numbers and store them in the linked list
    calculateFibonacci(&head, n - 1);

    // Print the nth Fibonacci number
    if (n > 0)
    {
        printFibNumber(head, n - 1);
    }
    else
    {
        printFibNumber(head, n);
    }

    // Free the memory allocated for the linked list
    Node *temp;
    while (head != NULL)
    {
        // Store the current head pointer in a temporary pointer variable
        temp = head;
        // Move the head pointer to the next node in the linked list
        head = head->next;
        // Free the memory allocated for the previous head node
        free(temp);
    }

    return 0;
}

// Function to create a new node with a given value
Node *createNode(int value)
{
    // Declare a pointer to a new node
    Node *newNode;
    // Allocate memory for the new node
    newNode = (Node *)malloc(sizeof(Node));

    // Check if memory allocation failed
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    // Initialize the new node with the given value and NULL next pointer
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node with a given value to the end of the linked list
void addNode(Node **head, int value)
{
    // Declare a pointer to a new node
    Node *newNode;
    // Create a new node with the given value
    newNode = createNode(value);

    // If the linked list is empty, make the new node the head
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        // Declare a temporary pointer to traverse the linked list
        Node *temp;
        temp = *head;

        // Traverse the linked list to find the last node
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Append the new node to the end of the linked list
        temp->next = newNode;
    }
}

// Function to calculate Fibonacci numbers and store them in the linked list
void calculateFibonacci(Node **head, int n)
{
    // Add the first two Fibonacci numbers (0 and 1) to the linked list if n is greater than or equal to 0 and 1
    if (n >= 0)
    {
        addNode(head, 0);
    }
    if (n >= 1)
    {
        addNode(head, 1);
    }

    // First Fibonacci number
    int first = 0;
    // Second Fibonacci number
    int second = 1;
    // Variable to store the current Fibonacci number
    int fib = 0;

    // Calculate Fibonacci numbers and add them to the linked list
    for (int i = 2; i <= n; ++i)
    {
        // Calculate the next Fibonacci number by adding the previous two Fibonacci numbers
        fib = first + second;
        // Add the newly calculated Fibonacci number to the linked list
        addNode(head, fib);
        // Update the value of 'first' to the previous value of 'second'
        first = second;
        // Update the value of 'second' to the newly calculated Fibonacci number
        second = fib;
    }
}

// Function to print the nth Fibonacci number
void printFibNumber(Node *head, int n)
{
    // Index of the current node in the linked list
    int index = 0;

    // Traverse the linked list until reaching the nth node or the end of the list
    while (head != NULL && index < n)
    {
        // Move to the next node
        head = head->next;
        // Increment the index
        index++;
    }

    // If the nth node exists, print its value
    if (head != NULL)
    {
        printf("%d\n", head->value);
    }
    // If the nth node does not exist (e.g., n = 0 and the list is empty), print 0
    else
    {
        printf("0\n", n);
    }
}
