// (C) __Parisa Babaei, Manely Abbasi, Meis Salim, group: 17 __ (2024)
// Work package 3
// Exercise 4
// Submission code: 040966

#include <Keypad.h> // Include the Keypad library

byte Rows = 4; // The number of rows of the keypad
byte Cols = 4; // The number of columns of the keypad

byte rowPins[4] = {11, 10, 9, 8}; // The row pinouts of the keypad
byte colPins[4] = {6, 5, 4, 3};   // The column pinouts of the keypad

char keys[4][4] = { // The characters on the keys of the keypad
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Create a Keypad object with the row and column pinouts and the characters on the keys
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, Rows, Cols);

void setup() { // Method that runs once when the sketch starts
  Serial.begin(9600); // Initialize the serial communication
}

void loop() { // Method that runs over and over again
  char currentKey = keypad.getKey(); // Get the character of the pressed key
  
  if (currentKey != 0){ // If a key is pressed
    Serial.println(currentKey); // Print the character of the pressed key to the serial monitor
  }
  
  delay(1000); // Delay for 1 second
}
