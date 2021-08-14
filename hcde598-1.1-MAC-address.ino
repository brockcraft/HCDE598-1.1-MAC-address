//Find the MAC address and other stuff regarding your esp32/esp8266

// brc 2020 added added compile time info
// updated for ESP32

#include "WiFi.h"          // Use this line for ESP32
//#include <ESP8266WiFi.h> // Use this line for ESP8266

String s;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // sets up the LED to blink
  Serial.begin(115200);
  Serial.println(""); // This line won't be printed
  
  Serial.println("This board is running: ");
  Serial.println(F(__FILE__));
  Serial.print("Compiled on: ");
  Serial.println(F(__DATE__ " " __TIME__));

  // Set WiFi to station mode and disconnect from an Access Point if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Setup done");
  s = WiFi.macAddress();
  Serial.println("Your mac address is: " + s);

  s = WiFi.softAPmacAddress();
  Serial.println("Your soft mac address is: " + s);

  s = ESP.getFreeSketchSpace();
  Serial.println("Your free sketch space is: " + s);

  s = ESP.getSketchSize();
  Serial.println("Your sketch size is: " + s);

//  s = ESP.getFlashChipRealSize();
//  Serial.println("Your chip size is: " + s);

  s = ESP.getSdkVersion();
  Serial.println("Your SDK version is: " + s);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);

}
