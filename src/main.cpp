#define OPEN false
#define CLOSE true
#define OPEN_STR "/open"
#define CLOSE_STR "/close"

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "Constants.h"

HTTPClient http;
WiFiClient client;



bool oldState = OPEN;
const string ssid = Constants::getSSID();
const string password = Constants::getPassword();
void setup()
{
  pinMode(D1, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println();
  WiFi.begin(ssid.c_str(), password.c_str());

  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("done.");
}

void loop()
{
                                                //  http.begin(client, "http://www.geekstips.com/esp8266-arduino-tutorial-iot-code-example/"); // 30KB payload
  bool newState = !digitalRead(D1);
  
  if(oldState != newState){
    oldState = newState;
    const string pathVariable = newState == OPEN ? OPEN_STR : CLOSE_STR; 
    http.begin(client, ("http://arcane-dawn-45409.herokuapp.com" + pathVariable).c_str()); // <1KB payload
    int httpCode = http.POST("");
    String payload = http.getString(); // Get the response payload
    Serial.println(httpCode); // Print HTTP return code
    Serial.println(payload);  // Print request response payload

    http.end(); // Close connection

    Serial.printf("Free heap: %d\n", ESP.getFreeHeap());
  }

  delay(200);
}