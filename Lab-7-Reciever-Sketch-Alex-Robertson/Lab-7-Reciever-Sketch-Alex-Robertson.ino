#include <SoftwareSerial.h>
#include <rgb_lcd.h>

SoftwareSerial mySerial(10, 11); //RX, TX pins

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
    String recievedMessage = mySerial.readString();
    lcd.print(recievedMessage);   // ... Display it on LCD
  }
}