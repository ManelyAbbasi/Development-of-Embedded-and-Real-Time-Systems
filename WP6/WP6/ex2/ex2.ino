// (C) __Parisa Babaei, Manely Abbasi, Meis Salim, group: 17 __ (2024)
// Work package 6
// Exercise 2
// Submission code: 601979

const int ultraPin = 7;             // Ultrasonic sensor pin
const int speakerPin = 9;           // Speaker pin
const int ledPins[] = {2, 3, 4, 5}; // Array of LED pins

const int ledLimits[] = {30, 75, 150, 200}; // Distance limits for LEDs

void setup() {
    Serial.begin(9600); // Start serial communication
    
    pinMode(speakerPin, OUTPUT); // Set speaker pin as output

    for (int i = 0; i < 4; i++) { // Loop through LED pins
        pinMode(ledPins[i], OUTPUT); // Set LED pin as output
    }
}

void loop() {
    float distance = readDistance(); // Read distance from ultrasonic sensor
    Serial.print("Distance: ");
    Serial.println(distance); // Print distance to serial monitor
    playSpeaker(distance); // Play speaker based on distance
    lightLEDs(distance); // Light LEDs based on distance
}

// Function to read distance from ultrasonic sensor
float readDistance() {
    pinMode(ultraPin, OUTPUT);      // Set ultrasonic pin as output
    digitalWrite(ultraPin, LOW);    // Send low pulse
    delayMicroseconds(2);           // Wait for 2 microseconds
    digitalWrite(ultraPin, HIGH);   // Send high pulse
    delayMicroseconds(10);          // Wait for 10 microseconds
    digitalWrite(ultraPin, LOW);    // Send low pulse
    pinMode(ultraPin, INPUT);       // Set ultrasonic pin as input
    int duration = pulseIn(ultraPin, HIGH); // Read duration of pulse
    float distance = duration * 0.01723;    // Calculate distance
    return distance;                        // Return distance
}

// Function to play speaker based on distance
void playSpeaker(float distance) {
    if (distance < 200) { // If distance is less than 200
        int pitch = map(distance, 25, 200, 4000, 1000); // Map distance to pitch
        tone(speakerPin, pitch); // Play tone
        delay(100);              // Wait for 100 milliseconds
    } else {                // If distance is greater than 200
        noTone(speakerPin); // Stop playing tone
    }
}

// Function to light LEDs based on distance
void lightLEDs(float distance) {
    for (int i = 0; i < 4; i++) {           // Loop through LED pins
        int limit = ledLimits[i];           // Get distance limit for LED
        if (distance < limit) {             // If distance is less than limit
            digitalWrite(ledPins[i], HIGH); // Light LED
        } else {                            // If distance is greater than limit
            digitalWrite(ledPins[i], LOW);  // Turn off LED
        }
    }
}
