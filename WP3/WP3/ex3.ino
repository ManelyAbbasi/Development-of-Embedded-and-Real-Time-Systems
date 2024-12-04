// (C) __Parisa Babaei, Manely Abbasi, Meis Salim, group: 17 __ (2024)
// Work package 3
// Exercise 3-again
// Submission code: 040966

int rowPins[4] = {11, 10, 9, 8}; // The row pinouts of the keypad
int colPins[4] = {6, 5, 4, 3};   // The column pinouts of the keypad

char keys[4][4] = { // The characters on the keys of the keypad
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

void setup() { // Method that runs once when the sketch starts
  for (int i = 0; i < 4; i++) { // Initialize the row pinouts of the keypad as outputs
    pinMode(rowPins[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++) { // Initialize the column pinouts of the keypad as inputs with pull-up resistors
    pinMode(colPins[i], INPUT_PULLUP); 
  }
    Serial.begin(9600); // Initialize the serial communication
}

void loop() { // Method that runs over and over again
  for (int i = 0; i < 4; i++) {    // For each row of the keypad
    digitalWrite(rowPins[i], LOW); // Set the current row to low

    for (int j = 0; j < 4; j++) { // For each column of the keypad
      if (digitalRead(colPins[j]) == LOW) { // If the key is pressed
        Serial.println(keys[i][j]); // Print the character of the pressed key to the serial monitor
      }
    }

    digitalWrite(rowPins[i], HIGH); // Set the current row to high
  }
  
  delay(1000); // Delay for 1 second
}
