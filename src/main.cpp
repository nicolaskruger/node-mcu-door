/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include "Arduino.h"
#include "Constants.h"

const String ssid = "";

void setup()
{
  // initialize LED digital pin as an output.'
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(D1, INPUT_PULLUP);
}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  
  bool turnOn = digitalRead(D1);

  if(turnOn){
    digitalWrite(LED_BUILTIN, HIGH);
  } else 
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
  
  // wait for a second
  delay(1000);
}