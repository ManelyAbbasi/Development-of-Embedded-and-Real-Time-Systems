// (C) __Parisa Babaei, Manely Abbasi, Meis Salim, group: 17 __ (2024)
// Work package 4
// Exercise 3
// Submission code: 639965


// The template for the code snippet was taken from the lecture material
// Based on the following tutorial: https://www.instructables.com/Arduino-Timer-Interrupts/

#include <Adafruit_NeoPixel.h>

const int pixelNumber = 12; // The number of LEDs in the ring
const int pixelPin = 2;     // The pin that the LED ring is connected to
// Create an instance of the Adafruit_NeoPixel class
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(pixelNumber, pixelPin, NEO_GRB + NEO_KHZ800);
int onPixel = 0; // The pixel that is currently on

const int tempPin = A1; // The pin that the temperature sensor is connected to
int tempReading;        // The reading from the temperature sensor
float tempVoltage;      // The voltage from the temperature sensor
float temp;             // The temperature in degrees Celsius

const int ledPin = 11; // The pin that the LED is connected to

void setup()
{
    pinMode(tempPin, INPUT); // Set the temperature sensor pin as an input

    setup_timer_1(); // Set up the timer

    pixels.begin(); // Initialize the LED ring

    Serial.begin(9600); // Start the serial communication
}

void loop() // The loop function is empty because the timer interrupt will handle the LED control
{
}

void setup_timer_1() // This function sets up the timer
{

    cli(); // Disable global interrupts

    TCCR1A = 0; // Set entire TCCR1A to 0
    TCCR1B = 0; // Set entire TCCR1B to 0
    TCNT1 = 0;  // Initialize counter value to 0

    OCR1A = 15624; // Set the value that you want to count to
    // OCR1A = 16 000 000 / (1024 * 1) - 1 = 15 625 - 1 = 15 624

    TCCR1B |= (1 << WGM12);              // Configure timer 1 for CTC mode
    TCCR1B |= (1 << CS12) | (1 << CS10); // Set CS12 and CS10 bits for 1024 prescaler

    TIMSK1 |= (1 << OCIE1A); // Enable the compare match interrupt

    sei(); // Enable global interrupts
}

ISR(TIMER1_COMPA_vect) // This function is called when the timer interrupt occurs
{
    cli(); // Disable global interrupts

    // Read the temperature sensor
    tempReading = analogRead(tempPin);
    // Convert the temperature sensor reading to a voltage
    tempVoltage = (tempReading * 5.0195) / 1024.0;
    // Convert the voltage to a temperature in degrees Celsius
    temp = (tempVoltage - 0.5) * 100;

    Serial.println(temp); // Print the temperature to the serial monitor

    onPixel = (int)map(temp, -40, 125, 0, pixelNumber); // Map the temperature to the number of LEDs to turn on

    for (int i = 0; i < pixelNumber; i++) // Loop through each LED in the ring
    {
        if (i < onPixel) // If the LED is less than the number of LEDs to turn on
        {
            pixels.setPixelColor(i, pixels.Color(255, 0, 0)); // Set the LED to red
        }
        else
        {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Set the LED to off
        }
    }

    if (onPixel == pixelNumber) // If all the LEDs are on
    {
        digitalWrite(ledPin, HIGH); // Turn on the red LED
    }
    else
    {
        digitalWrite(ledPin, LOW); // Turn off the red LED
    }

    pixels.show(); // Update the LED ring

    sei(); // Enable global interrupts
}
