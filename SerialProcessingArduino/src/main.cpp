#include <Arduino.h>
Napiši program ZA vklapljanje ledic!


char incomingByte;
void setup() {
  Serial.begin(9600);
  pinMode(10,OUTPUT);
}
void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    Serial.print(incomingByte);
    if(incomingByte == 'B'){
      Serial.print('C');
      digitalWrite(10,!digitalRead(10));
    }
  }
}