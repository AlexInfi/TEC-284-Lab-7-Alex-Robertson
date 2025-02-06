#include <SoftwareSerial.h>
#include <rgb_lcd.h>
#include <Wire.h>

SoftwareSerial mySerial(6, 7); //RX, TX pins

rgb_lcd lcd;

void setup() {
  Serial.begin(9600); // Initialize hardware serial connection
  mySerial.begin(9600); // Initialize SoftwareSerial connection
  
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print("Waiting...");

  // If information is ready to be read...
  if (mySerial.available() > 0) {
    lcd.clear();
    lcd.setCursor(0, 1);
    String recievedMessage = mySerial.readString();
    lcd.print(recievedMessage);   // ... Display it on LCD
    delay(1000);
  }
}