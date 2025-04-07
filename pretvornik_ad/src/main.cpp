#include <Arduino.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  int napetost = analogRead(A0);
  int svet = napetost/1023.0*255.0;
  Serial.println(svet);
  analogWrite(9, svet);
  delay(100);
}
