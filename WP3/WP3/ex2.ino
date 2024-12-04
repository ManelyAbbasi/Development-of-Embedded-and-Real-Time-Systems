// (C) __Parisa Babaei, Manely Abbasi, Meis Salim, group: 17 __ (2024)
// Work package 3
// Exercise 2
// Submission code: 040966

const int lightPin = 4; // The number of the light sensor pin
const int tempPin = 5;  // The number of the temperature sensor pin
const int bluePin = 2;  // The number of the blue LED pin
const int greenPin = 3; // The number of the green LED pin
const int redPin = 4;   // The number of the red LED pin

int periodicity = 1; // The periodicity of the measurements in seconds

enum Color // The possible colors of the LED
{
    RED,
    GREEN,
    BLUE
};

int tempReading;    // The reading from the temperature sensor
float tempVoltage;  // The voltage from the temperature sensor
float temp;         // The temperature in degrees Celsius
int lightReading;   // The reading from the light sensor
int light;          // The light in percentage
Color color;        // The color of the LED

void setup() // Method that runs once when the sketch starts
{
    pinMode(lightPin, INPUT);   // Initialize the light sensor pin as an input
    pinMode(tempPin, INPUT);    // Initialize the temperature sensor pin as an input
    pinMode(bluePin, OUTPUT);   // Initialize the blue LED pin as an output
    pinMode(greenPin, OUTPUT);  // Initialize the green LED pin as an output
    pinMode(redPin, OUTPUT);    // Initialize the red LED pin as an output
    Serial.begin(9600);         // Initialize the serial communication
}

void loop() // Method that runs over and over again
{
    digitalWrite(redPin, LOW);  // Turn the red LED off
    digitalWrite(greenPin, LOW); // Turn the green LED off
    digitalWrite(bluePin, LOW);  // Turn the blue LED off

    // Read the light sensor
    lightReading = analogRead(lightPin);
    // Map the light sensor reading to a percentage
    light = map(lightReading, 0, 1023, 0, 100);

    // Read the temperature sensor
    tempReading = analogRead(tempPin);
    // Convert the temperature sensor reading to a voltage
    tempVoltage = (tempReading * 5.0195) / 1024.0;
    // Convert the voltage to a temperature in degrees Celsius
    temp = (tempVoltage - 0.5) * 100;

    if (light == 0)      // If the light is 0%
    {
        if (temp >= -12)    // If the temperature is above -12°C
        {
            color = RED;    // Set the LED to red
        }
        else                // If the temperature is below -12°C
        {
            color = GREEN;  // Set the LED to green
        }
    }
    else if (light > 0 && light <= 20) // If the light is between 0% and 20%
    {
        if (temp < -12)     // If the temperature is below -12°C
        {
            color = BLUE;   // Set the LED to blue
        }
        else if (temp >= 0) // If the temperature is above 0°C
        {
            color = RED;    // Set the LED to red
        }
        else                // If the temperature is between -12°C and 0°C
        {
            color = GREEN;  // Set the LED to green
        }
    }
    else if (light > 20 && light <= 60) // If the light is between 20% and 60%
    {
        if (temp < 0)        // If the temperature is below 0°C
        {
            color = BLUE;    // Set the LED to blue
        }
        else if (temp >= 21) // If the temperature is above 21°C
        {
            color = RED;     // Set the LED to red
        }
        else                 // If the temperature is between 0°C and 21°C
        {
            color = GREEN;   // Set the LED to green
        }
    }
    else if (light > 60)     // If the light is above 60%
    {
        if (temp < 21)       // If the temperature is below 21°C
        {
            color = BLUE;    // Set the LED to blue
        }
        else                 // If the temperature is above 21°C
        {
            color = GREEN;   // Set the LED to green
        }
    }

    // Print the temperature, light, and color to the serial monitor
    Serial.print("temperature: ");
    Serial.print(temp);
    Serial.print("°C light: ");
    Serial.print(light);
    Serial.print(" color: ");

    switch (color) // Switch for the color of the LED
    {
    case RED: // If the color is red
        digitalWrite(redPin, HIGH);  // Turn the red LED on
        Serial.println("RED");       // Print "RED" to the serial monitor
        break;                       // Break out of the switch

    case GREEN:
        digitalWrite(greenPin, HIGH); // Turn the green LED on
        Serial.println("GREEN");      // Print "GREEN" to the serial monitor
        break;                        // Break out of the switch

    case BLUE:
        digitalWrite(bluePin, HIGH); // Turn the blue LED on
        Serial.println("BLUE");      // Print "BLUE" to the serial monitor
        break;                       // Break out of the switch

    default:    // If the color is not red, green, or blue
        break;  // Break out of the switch
    }
    
    delay(periodicity * 1000); // Wait for the periodicity in milliseconds
}
