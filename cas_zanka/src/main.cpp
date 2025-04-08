#include <Arduino.h>

uint32_t trent_cas;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  while ((millis() - trent_cas) < 250)
    ;
  trent_cas = millis();
  Serial.println(trent_cas);
  digitalWrite(13, !digitalRead(13));
  digitalWrite(12, !digitalRead(12));
  digitalWrite(11, !digitalRead(11));
}
