// (C) __Parisa Babaei, Manely Abbasi, Meis Salim, group: 17 __ (2024)
// Work package 3
// Exercise 2
// Submission code: 040966

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
}
void loop()
{
    // Turns the first LED on by making voltage high
    digitalWrite(LED_BUILTIN, HIGH);
    // Waits for 10 milliseconds (blink time)
    delay(10);
    // Turns the LED off by making the voltage LOW
    digitalWrite(LED_BUILTIN, LOW);
    // Wait for 2000 milliseconds between blinks.
    delay(2000);
    // Blinks every 2 seconds.
}