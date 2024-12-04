// (C) __Parisa Babaei, Manely Abbasi, Meis Salim, group: 17 __ (2024)
// Work package 4
// Exercise 1
// Submission code: 639965

// The template for the code snippet was taken from the lecture material
// Based on the following tutorial: https://www.instructables.com/Arduino-Timer-Interrupts/

#define PRESCALER 1024       // The prescaler value used for the timer
#define INTERRUPT_FREQ 1     // The frequency of the interrupt in Hz
#define CLOCK_SPEED 16000000 // The clock speed of the Arduino in Hz
#define TIMER1_MAX 65535     // The maximum value that the timer can count to
#define TIMER1_LOW 257       // The minimum value that the timer can count to

const int ledPins[] = {10, 8, 7, 4, 2}; // The pins that the LEDs are connected to
const int ledCount = 5;                 // The number of LEDs

const int tempLimits[] = {0, 10, 20, 30, 40}; // The temperature limits for the LEDs

const int tempPin = 5; // The pin that the temperature sensor is connected to

int tempReading;   // The reading from the temperature sensor
float tempVoltage; // The voltage from the temperature sensor
float temp;        // The temperature in degrees Celsius

int timer1 = 0; // The value that the timer will count to

void setup()
{
   for (int i = 0; i < ledCount; i++) // loop through each LED pin
   {
      pinMode(ledPins[i], OUTPUT); // Set the LED pin as an output
   }

   pinMode(tempPin, INPUT); // Set the temperature sensor pin as an input

   setup_timer_1();    // Set up the timer
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

   // Calculate the value that you want to count to
   timer1 = (CLOCK_SPEED / (PRESCALER * INTERRUPT_FREQ)) - 1;
   // timer1 = 16 000 000 / (1024 * 1) - 1 = 15 625 - 1 = 15 624

   if (timer1 >= TIMER1_MAX) // Check if the value is too high
   {
      timer1 = TIMER1_MAX; // If it is, set it to the maximum value
      Serial.println((String) "timer1 was set too high and was changed to: " + timer1);
   }
   else if (timer1 <= TIMER1_LOW) // Check if the value is too low
   {
      timer1 = TIMER1_LOW; // If it is, set it to the minimum value
      Serial.println((String) "timer1 was set too low and was changed to: " + timer1);
   }

   OCR1A = timer1; // Set the value that you want to count to

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

   for (int i = 0; i < ledCount; i++) // Loop through each LED pin
   {
      if (temp > tempLimits[i]) // Check if the temperature is below the limit for the current LED
      {
         digitalWrite(ledPins[i], HIGH); // Turn on the LED
      }
      else
      {
         digitalWrite(ledPins[i], LOW); // Turn off the LED
      }
   }

   sei(); // Enable global interrupts
}
