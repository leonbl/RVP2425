#include <Arduino.h>

void setup() {
  pinMode(A3,OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  int nap = analogRead(A0);
  digitalWrite(A3, HIGH);
  delay(1);
  delayMicroseconds(nap);
  digitalWrite(A3, LOW);
  delay(20);
}
