// (C) __Parisa Babaei, Manely Abbasi, Meis Salim, group: 17 __ (2024)
// Work package 4
// Exercise 2
// Submission code: 639965


// The template for the code snippet was taken from the lecture material
// Based on the following tutorial: https://www.instructables.com/Arduino-Timer-Interrupts/

#include <Servo.h>

int pos = 0;      // The position of the servo
Servo servo;      // Create a servo object to control the servo
int servoPin = 9; // The pin that the servo is connected to

int seconds = 0; // The number of seconds that have passed
int counter = 0; // The number of times the interrupt has been called

void setup()
{
   setup_timer_2();                   // Set up the timer
   servo.attach(servoPin, 500, 2500); // Attach the servo to the pin
   servo.write(0);
   Serial.begin(9600);                // Start the serial communication
}

void loop()
{
}

void setup_timer_2()
{

   cli(); // Disable global interrupts

   TCCR2A = 0; // Set entire TCCR2A to 0
   TCCR2B = 0; // Set entire TCCR2B to 0
   TCNT2 = 0;  // Initialize counter value to 0

   OCR2A = 124; // Set the compare match register for desired frequency 125 Hz
   // (16 000 000 / (1024 * 125) - 1 = 124)

   TCCR2B |= (1 << WGM21);                            // Set the WGM mode to CTC
   TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); // Set the prescaler to 1024

   TIMSK2 |= (1 << OCIE2A); // Enable the compare match interrupt

   sei(); // Enable global interrupts
}

ISR(TIMER2_COMPA_vect)
{
   cli(); // Disable global interrupts
   counter++;
   if (counter == 125) // If 1 second has passed
   {
      seconds++;   // Increment the number of seconds
      counter = 0; // Reset the counter

      if (pos == 180)
      {           // If the servo is at the maximum position
         pos = 0; // Set the position to the minimum
      }
      else
      {            // Otherwise
         pos += 1; // Increment the position
      }

      servo.write(pos); // Set the servo to the new position

      Serial.println((String) "Seconds: " + seconds); // Print the number of seconds
   }
   sei(); // Enable global interrupts
}
