#include <SoftwareSerial.h>

SoftwareSerial mySerial(7, 6);  // TX, RX pins


void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  mySerial.print(Serial.readStringUntil('\n'));
}